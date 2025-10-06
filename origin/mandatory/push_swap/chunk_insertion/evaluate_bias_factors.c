/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_bias_factors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:17:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 16:14:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	evaluate_bias_factors(t_ctx *ctx, double rotate_b_bias_factor, \
			double big_element_bias_factor, double rotate_a_bias_factor)
{
	if (ctx->chunk_insertion_cost < ctx->min_chunk_insertion_cost)
	{
		ctx->min_chunk_insertion_cost = ctx->chunk_insertion_cost;
		ctx->best_rotate_b_bias_factor = rotate_b_bias_factor;
		ctx->best_big_element_bias_factor = big_element_bias_factor;
		ctx->best_rotate_a_bias_factor = rotate_a_bias_factor;
		// printf("%zu\n", ctx->min_chunk_insertion_cost);
	}
}
