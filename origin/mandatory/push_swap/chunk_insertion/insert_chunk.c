/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/29 17:40:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_prev_order_replaceable_with_swap(t_ctx *ctx);
void	replace_rotate_with_swap(t_ctx *ctx);

void	insert_chunk(t_ctx *ctx, int pushed_count)
{
	t_target_element	target;
	int					half_count;

	half_count = pushed_count / 2;
	while (pushed_count > 0)
	{
		target = search_min_cost_target(ctx);
		if (target.is_up_rotate_b == false && is_prev_order_replaceable_with_swap(ctx) == true)
			replace_rotate_with_swap(ctx);
		order_insert(ctx, target);
		renew_insert_positions(ctx, target.element->index);
		ctx->chunk_insertion_cost += calc_insertion_cost((*(ctx->current_order))->prev);
		pushed_count--;
		ctx->rra_cost_to_max_insert_position = 0;
		if (pushed_count <= half_count && is_prev_order_replaceable_with_swap(ctx) == false)
		{
			search_best_biases(ctx, pushed_count);
			half_count /= 2;
			if (pushed_count < 8)
				half_count = 0;
		}
	}
	ctx->chunk_insertion_cost += calc_rra_cost_to_min_chunk_element(ctx);
	// printf("\n");
}

void	simulate_insert_chunk(t_ctx *ctx, int pushed_count)
{
	t_target_element	target;

	while (pushed_count > 0)
	{
		target = search_min_cost_target(ctx);
		if (target.is_up_rotate_b == false && is_prev_order_replaceable_with_swap(ctx) == true)
			replace_rotate_with_swap(ctx);
		order_insert(ctx, target);
		renew_insert_positions(ctx, target.element->index);
		ctx->chunk_insertion_cost += calc_insertion_cost((*(ctx->current_order))->prev);
		if (ctx->chunk_insertion_cost > ctx->min_chunk_insertion_cost)
			return ; 
		pushed_count--;
		ctx->rra_cost_to_max_insert_position = 0;
	}
	ctx->chunk_insertion_cost += calc_rra_cost_to_min_chunk_element(ctx);
}

bool	is_prev_order_replaceable_with_swap(t_ctx *ctx)
{
	t_order *prev_order;

	prev_order = (*(ctx->current_order))->prev;
	if (prev_order->pa == true && prev_order->rb > 0)
		return (true);
	return (false);
}

void	replace_rotate_with_swap(t_ctx *ctx)
{
	t_order *prev_order;

	prev_order = (*(ctx->current_order))->prev;
	prev_order->pa = false;
	prev_order->rb--;
	prev_order->sb = true;
	add_order(ctx, "pa");
	add_order(ctx, "rb");
}
