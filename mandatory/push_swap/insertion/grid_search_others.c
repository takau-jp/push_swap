/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_search_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 03:16:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 14:53:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	baseline_model(t_ctx *ctx, int pushed_count)
{
	ctx->rotate_b_bias_factor = 1.83;
	ctx->big_element_bias_factor = 0.8;
	ctx->rotate_a_bias_factor = 1.0;
	simulate_insert_chunk(ctx, pushed_count);
	evaluate_bias_factors(ctx, 1.83, 0.8, 1.0);
	restore_stacks(ctx);
	restore_info(ctx);
}


void	grid_search_big_element(t_ctx *ctx, int pushed_count)
{
	int		count;
	double	big_element_bias_factor;

	big_element_bias_factor = 0.0;
	count = 0;
	while (big_element_bias_factor <= 5.0) 
	{
		if (count++ % 20 == 0)
		{
			big_element_bias_factor += 0.01;
			continue;
		}
		// if (!(ctx->rotate_b_bias_factor >= ctx->grid_search_slope * ctx->big_element_bias_factor - 1.5))
		// 	break ;
		// if (!(ctx->rotate_b_bias_factor <= ctx->grid_search_slope * ctx->big_element_bias_factor + 3.5))
		// {
		// 	ctx->big_element_bias_factor += 0.01;
		// 	continue;
		// }
		ctx->big_element_bias_factor = big_element_bias_factor;
		simulate_insert_chunk(ctx, pushed_count);
		evaluate_bias_factors(ctx, ctx->best_rotate_b_bias_factor, big_element_bias_factor, ctx->best_rotate_a_bias_factor);
		restore_stacks(ctx);
		restore_info(ctx);
		big_element_bias_factor += 0.01;
	}
}

void	grid_search_rotate_a(t_ctx *ctx, int pushed_count)
{
	double rotate_a_bias_factor;
	
	rotate_a_bias_factor = 0.0;
	while (rotate_a_bias_factor <= 3.0) 
	{
		if (rotate_a_bias_factor == 1.0)
			rotate_a_bias_factor += 0.01;
		ctx->rotate_a_bias_factor = rotate_a_bias_factor;
		simulate_insert_chunk(ctx, pushed_count);
		evaluate_bias_factors(ctx, ctx->best_rotate_b_bias_factor, ctx->best_big_element_bias_factor, rotate_a_bias_factor);
		restore_stacks(ctx);
		restore_info(ctx);
		rotate_a_bias_factor += 0.01;
	}
}
