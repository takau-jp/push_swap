/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_last_chunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:31:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 16:28:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	biased_rotate_cost_last_chunk(t_ctx *ctx, ssize_t rotate_b_cost, ssize_t rra_cost);
ssize_t	biased_element_cost_last_chunk(t_ctx *ctx, t_element *element);

ssize_t	calc_cost_last_chunk(
			t_ctx *ctx, t_element *element, t_rotate_cost *rotate_cost, t_rotate_func rotate)
{
	ssize_t	cost;

	if (rotate == up_rotate)
	{
		rotate_cost->a_same = ctx->elements_by_index[element->insert_position]->ra_rotate_cost;
		rotate_cost->a_reverse = ctx->elements_by_index[element->insert_position]->rra_rotate_cost;
	}
	else
	{
		rotate_cost->a_same = ctx->elements_by_index[element->insert_position]->rra_rotate_cost;
		rotate_cost->a_reverse = ctx->elements_by_index[element->insert_position]->ra_rotate_cost;
	}
	if (rotate_cost->b < rotate_cost->a_same)
	{
		if (rotate_cost->a_same < rotate_cost->a_reverse + rotate_cost->b)
		{
			cost = rotate_cost->a_same;
			rotate_cost->a_reverse = 0;
			if (rotate != up_rotate)
				cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, rotate_cost->a_same);
			else
				cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, 0);
		}
		else
		{
			cost = rotate_cost->a_reverse + rotate_cost->b;
			rotate_cost->a_same = 0;
			if (rotate == up_rotate)
				cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, rotate_cost->a_reverse);
			else
				cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, 0);
		}
	}
	else
	{
		cost = rotate_cost->b;
		rotate_cost->a_reverse = 0;
		if (rotate != up_rotate)
			cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, rotate_cost->a_same);
		else
			cost += biased_rotate_cost_last_chunk(ctx, rotate_cost->b, 0);
	}
	cost += biased_element_cost_last_chunk(ctx, element);
	return (cost);
}


ssize_t	biased_rotate_cost_last_chunk(t_ctx *ctx, ssize_t rotate_b_cost, ssize_t rra_cost)
{
	ssize_t	biased_cost;
	
	biased_cost = rotate_b_cost * ctx->rotate_b_bias_factor;
	rra_cost -= ctx->rra_cost_to_max_insert_position;
	// biased_cost += rra_cost * ctx->rotate_a_bias_factor;
	biased_cost += rra_cost;
	return (biased_cost);
}

ssize_t	biased_element_cost_last_chunk(t_ctx *ctx, t_element *element)
{
	return ((double)(ctx->max_pushed_element_index - element->index) * ctx->big_element_bias_factor);
}
