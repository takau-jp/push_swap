/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 05:28:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_insert(t_ctx *ctx, t_push_target target);
void	evaluate_cost(t_ctx *ctx, int cost);

void	insert_chunk(t_ctx *ctx)
{
	t_push_target	target;
	int				half_size;

	half_size = ctx->chunk_size / 2;
	set_insert_positions(ctx);
	while (ctx->stack_b.size && ctx->chunk_size > 0)
	{
		target = search_min_cost_target(ctx);
		order_insert(ctx, target);
		ctx->chunk_size--;
		renew_insert_positions(ctx, target.element->rank);
		if (ctx->chunk_size > 8 && ctx->chunk_size < half_size)
		{
			search_best_biases(ctx);
			half_size = ctx->chunk_size / 2;
			set_insert_positions(ctx);
		}
	}
}

void	simulate_insert_chunk(t_ctx *ctx)
{
	t_push_target	target;
	int				cost;
	int				pushed_count;

	set_insert_positions(ctx);
	cost = 0;
	pushed_count = 0;
	while (ctx->stack_b.size && pushed_count < ctx->chunk_size)
	{
		target = search_min_cost_target(ctx);
		order_insert(ctx, target);
		renew_insert_positions(ctx, target.element->rank);
		cost += calc_push_cost(\
					ctx->current_order->prev, ctx->current_order->prev->prev);
		pushed_count++;
		if (ctx->best_state.cost < cost)
			return ;
	}
	cost += calc_rotation_cost(\
				ctx->stack_a.top, ctx->min_chunk_element->rank, down_rotate);
	evaluate_cost(ctx, cost);
}

void	order_insert(t_ctx *ctx, t_push_target target)
{
	if (target.rotate_a == up_rotate)
		execute_rotate_orders(ctx, target.rotation_cost_a, ra);
	else
		execute_rotate_orders(ctx, target.rotation_cost_a, rra);
	if (target.rotate_b == up_rotate)
		execute_rotate_orders(ctx, target.rotation_cost_b, rb);
	else
		execute_rotate_orders(ctx, target.rotation_cost_b, rrb);
	pa(ctx);
	target.element->state = SORTED;
}

void	evaluate_cost(t_ctx *ctx, int cost)
{
	if (ctx->best_state.cost > cost)
	{
		ctx->best_state.cost = cost;
		ctx->best_state.bias.rotate_b = ctx->bias.rotate_b;
		ctx->best_state.bias.big_element = ctx->bias.big_element;
	}
}
