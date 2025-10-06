/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:32:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/27 17:32:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decrement_pushed_count_big_chunk(t_ctx *ctx, t_chunk *chunk, t_efficient_rotate *rotation);
void	decrement_pushed_count_small_chunk(t_ctx *ctx, t_chunk *chunk, t_efficient_rotate *rotation);

void	push_chunk(t_ctx *ctx, t_chunk *chunk, \
			t_efficient_rotate rotation, t_rotate_func rotate)
{
	t_target_element	target;

	while (rotation.is_end_big_chunk == false || rotation.is_end_small_chunk == false)
	{
		target.element = *(ctx->stack_a);
		target.rotate_cost_a = 0;
		while (target.element->is_pushed == false)
		{
			target.element = rotate(target.element);
			target.rotate_cost_a++;
		}
		order_push(ctx, chunk, target, rotate);
		if (target.element == rotation.pivot_element)
			rotate = reverse_rotate(rotate);
		if (target.element->chunk_number == chunk->big_number)
			decrement_pushed_count_big_chunk(ctx, chunk, &rotation);
		if (target.element->chunk_number == chunk->small_number)
			decrement_pushed_count_small_chunk(ctx, chunk, &rotation);
	}
}

void	decrement_pushed_count_big_chunk(t_ctx *ctx, t_chunk *chunk, t_efficient_rotate *rotation)
{
	chunk->pushed_count_in_big--;
	if (chunk->pushed_count_in_big == 0)
	{
		rotation->is_end_big_chunk = true;
		if (chunk->big_number == chunk->small_number)
		{
			chunk->is_end = true;
			return ;
		}
		if (chunk->big_number == ctx->chunk_count - 1)
			chunk->big_number = 0;
		else
			chunk->big_number++;
		mark_pushed_for_division_big_chunk(ctx, chunk);
	}
}

void	decrement_pushed_count_small_chunk(t_ctx *ctx, t_chunk *chunk, t_efficient_rotate *rotation)
{
	if (chunk->small_number == ctx->chunk_count - 1)
		return ;
	chunk->pushed_count_in_small--;
	if (chunk->pushed_count_in_small == 0)
	{
		rotation->is_end_small_chunk = true;
		if (chunk->big_number == chunk->small_number)
		{
			chunk->is_end = true;
			return ;
		}
		if (chunk->small_number == 0)
		{
			chunk->small_number = ctx->chunk_count - 1;
			return ;
		}
		else
			chunk->small_number--;
		mark_pushed_for_division_small_chunk(ctx, chunk);
	}
}