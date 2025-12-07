/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_division.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:45:40 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:52:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_efficient_rotation	get_efficient_rotation(t_ctx *ctx);
void					push_top_target(t_ctx *ctx, \
	t_chunk *big_chunk, t_chunk *small_chunk);
void					push_chunk(t_ctx *ctx, \
	t_chunk *big_chunk, t_chunk *small_chunk, t_efficient_rotation rotation);

void	chunk_division(t_ctx *ctx)
{
	t_chunk					big_chunk;
	t_chunk					small_chunk;
	t_efficient_rotation	rotation;

	big_chunk.number = ctx->chunk_count / 2;
	small_chunk.number = ctx->chunk_count / 2 - 1;
	mark_push_target_for_division(ctx, &big_chunk);
	if (small_chunk.number != -1)
		mark_push_target_for_division(ctx, &small_chunk);
	push_top_target(ctx, &big_chunk, &small_chunk);
	while (ctx->stack_b.size < ctx->unsorted_count)
	{
		rotation = get_efficient_rotation(ctx);
		push_chunk(ctx, &big_chunk, &small_chunk, rotation);
		if (ctx->stack_b.size == ctx->unsorted_count)
			break ;
		renew_push_target(ctx, &big_chunk, &small_chunk);
		push_top_target(ctx, &big_chunk, &small_chunk);
	}
}

t_efficient_rotation	get_efficient_rotation(t_ctx *ctx)
{
	t_efficient_rotation	rotation;
	int64_t					best_cost;

	set_cost_data(ctx, up_rotate);
	set_cost_data(ctx, down_rotate);
	best_cost = INT64_MAX;
	calc_best_cost_rotation_without_pivot(ctx, &best_cost, &rotation);
	return (rotation);
}

void	push_top_target(t_ctx *ctx, t_chunk *big_chunk, t_chunk *small_chunk)
{
	while (ctx->stack_a.top->state & PUSH_TARGET)
	{
		while (ctx->stack_a.top->state & PUSH_TARGET)
		{
			if (ctx->stack_a.top->chunk_number == big_chunk->number)
				big_chunk->count--;
			else
				small_chunk->count--;
			pb(ctx);
			ctx->stack_b.top->state &= ~PUSH_TARGET;
			if (ctx->stack_b.top->chunk_number == small_chunk->number)
				rb(ctx);
		}
		if ((big_chunk->number != ctx->chunk_count && big_chunk->count == 0) \
			|| (small_chunk->number != -1 && small_chunk->count == 0))
		{
			renew_push_target(ctx, big_chunk, small_chunk);
		}
	}
}

void	push_chunk(t_ctx *ctx, \
	t_chunk *big_chunk, t_chunk *small_chunk, t_efficient_rotation rotation)
{
	while (!(big_chunk->number != ctx->chunk_count && big_chunk->count == 0) \
			&& !(small_chunk->number != -1 && small_chunk->count == 0))
	{
		while (!(ctx->stack_a.top->state & PUSH_TARGET))
		{
			if (rotation.rotate == up_rotate)
				ra(ctx);
			else
				rra(ctx);
		}
		if (ctx->stack_a.top->chunk_number == big_chunk->number)
			big_chunk->count--;
		else
			small_chunk->count--;
		if (ctx->stack_a.top == rotation.pivot)
			rotation.rotate = reverse_rotate(rotation.rotate);
		pb(ctx);
		ctx->stack_b.top->state &= ~PUSH_TARGET;
		if (ctx->stack_b.top->chunk_number == small_chunk->number)
			rb(ctx);
	}
}
