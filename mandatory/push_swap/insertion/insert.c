/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/04 00:11:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_prev_order_replaceable_with_swap(t_ctx *ctx);
void	replace_rotate_with_swap(t_ctx *ctx);

void	insert(t_ctx *ctx)
{
	t_target_element	target;
	int					count;

	count = 10;
	while (ctx->size_b)
	{
		target = search_min_cost_target(ctx);
		if (target.is_up_rotate_b == false && is_prev_order_replaceable_with_swap(ctx) == true)
			replace_rotate_with_swap(ctx);
		order_insert(ctx, target);
		renew_insert_positions(ctx, target.element->index);
		ctx->chunk_insertion_cost += calc_insertion_cost((*(ctx->current_order))->prev);
		if (target.element->index == ctx->max_pushed_element_index)
			count--;
		if (count == 0)
		{
			search_best_biases(ctx);
			count = 10;
		}
	}
}

void	simulate_insert(t_ctx *ctx)
{
	t_target_element	target;
	int					count;

	count = 10;
	while (ctx->size_b && count > 0)
	{
		target = search_min_cost_target(ctx);
		if (target.is_up_rotate_b == false && is_prev_order_replaceable_with_swap(ctx) == true)
			replace_rotate_with_swap(ctx);
		order_insert(ctx, target);
		renew_insert_positions(ctx, target.element->index);
		ctx->chunk_insertion_cost += calc_insertion_cost((*(ctx->current_order))->prev);
		if (target.element->index == ctx->max_pushed_element_index)
			count--;
	}
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
