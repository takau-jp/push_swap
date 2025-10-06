/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:30:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/02 01:34:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	biased_rotate_cost(t_ctx *ctx, ssize_t rb_cost, ssize_t rra_cost);
ssize_t	biased_element_cost(t_ctx *ctx, t_element *element);

ssize_t	calc_cost(
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
		}
		else
		{
			cost = rotate_cost->a_reverse + rotate_cost->b;
			rotate_cost->a_same = 0;
		}
	}
	else
	{
		cost = rotate_cost->b;
		rotate_cost->a_reverse = 0;
	}
	cost += biased_rotate_cost(ctx, rotate_cost->b);
	cost += biased_element_cost(ctx, element);
	return (cost);
}


ssize_t	biased_rotate_cost(t_ctx *ctx, ssize_t rotate_b_cost)
{
	return (rotate_b_cost * ctx->rotate_b_bias_factor);
}

ssize_t	biased_element_cost(t_ctx *ctx, t_element *element)
{
	return ((double)(ctx->max_pushed_element_index - element->index) * ctx->big_element_bias_factor);
}
