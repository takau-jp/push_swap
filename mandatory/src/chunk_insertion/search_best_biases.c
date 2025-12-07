/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_best_biases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:02:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 10:23:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random_search(t_ctx *ctx);
void	grid_search(t_ctx *ctx);

void	search_best_biases(t_ctx *ctx)
{
	ctx->restore.confirmed_order_node = ctx->current_order->prev;
	ctx->restore.max_unsorted_element = ctx->max_unsorted_element;
	ctx->best_state.cost = ft_get_infinity();
	calc_search_area(ctx);
	random_search(ctx);
	grid_search(ctx);
	ctx->bias.rotate_b = ctx->best_state.bias.rotate_b;
	ctx->bias.big_element = ctx->best_state.bias.big_element;
}

void	random_search(t_ctx *ctx)
{
	int					search_count;
	const t_search_area	search_area = ctx->search_area;

	search_count = ctx->search_area.random_search_count;
	while (search_count > 0)
	{
		if (range_random(ctx, 0.0, 1.0) < 0.5)
		{
			ctx->bias.rotate_b = range_random(ctx, \
				search_area.min_rotate_b, search_area.max_rotate_b);
			ctx->bias.big_element = range_random(ctx, \
				search_area.min_big_element, search_area.max_big_element);
		}
		else
		{
			ctx->bias.rotate_b = range_random(ctx, 0.0, 10.0);
			ctx->bias.big_element = range_random(ctx, 0.0, 5.0);
		}
		simulate_insert_chunk(ctx);
		restore(ctx);
		search_count--;
	}
}

void	grid_search(t_ctx *ctx)
{
	double	rotate_b_bias_factor;
	double	big_element_bias_factor;

	rotate_b_bias_factor = ctx->best_state.bias.rotate_b - 1.5;
	while (rotate_b_bias_factor <= ctx->best_state.bias.rotate_b + 1.5)
	{
		big_element_bias_factor = ctx->best_state.bias.big_element - 1.5;
		while (big_element_bias_factor \
				<= ctx->best_state.bias.big_element + 1.5)
		{
			ctx->bias.rotate_b = rotate_b_bias_factor;
			ctx->bias.big_element = big_element_bias_factor;
			simulate_insert_chunk(ctx);
			restore(ctx);
			big_element_bias_factor += 0.1;
		}
		rotate_b_bias_factor += 0.1;
	}
}
