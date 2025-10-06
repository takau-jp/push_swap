/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_search_rotate_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:42:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 16:12:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_grid_search_rotate_b(t_ctx *ctx, int pushed_count)
{
	double rotate_b_bias_factor;
	double big_element_bias_factor;

	rotate_b_bias_factor = -3.0;
	while (rotate_b_bias_factor <= 10.0) 
	{
		big_element_bias_factor = 0.0;
		while (big_element_bias_factor <= 5.0)
		{
			// if (!(ctx->rotate_b_bias_factor >= ctx->grid_search_slope * ctx->big_element_bias_factor - 3.0))
			// 	break ;
			// if (!(ctx->rotate_b_bias_factor <= ctx->grid_search_slope * ctx->big_element_bias_factor + 3.5))
			// {
			// 	ctx->big_element_bias_factor += 0.2;
			// 	continue;
			// }
			ctx->rotate_b_bias_factor = rotate_b_bias_factor;
			ctx->big_element_bias_factor = big_element_bias_factor;
			simulate_insert_chunk(ctx, pushed_count);
			evaluate_bias_factors(ctx, rotate_b_bias_factor, big_element_bias_factor, ctx->best_rotate_a_bias_factor);
			restore_stacks(ctx);
			restore_info(ctx);
			big_element_bias_factor += 0.2;
		}
		rotate_b_bias_factor += 0.2;
	}
}

void	second_grid_search_rotate_b(t_ctx *ctx, int pushed_count)
{
	double rotate_b_bias_factor;
	double big_element_bias_factor;

	rotate_b_bias_factor = ctx->best_rotate_b_bias_factor -1.5;
	while (rotate_b_bias_factor <= ctx->best_rotate_b_bias_factor + 1.5) 
	{
		if ((double)(int)rotate_b_bias_factor == rotate_b_bias_factor)
			rotate_b_bias_factor += 0.1;
		big_element_bias_factor = 0.0;
		while (big_element_bias_factor <= 5.0)
		{
			// if (!(ctx->rotate_b_bias_factor >= ctx->grid_search_slope * ctx->big_element_bias_factor - 3.0))
			// 	break ;
			// if (!(ctx->rotate_b_bias_factor <= ctx->grid_search_slope * ctx->big_element_bias_factor + 3.5))
			// {
			// 	ctx->big_element_bias_factor += 0.2;
			// 	continue;
			// }
			ctx->rotate_b_bias_factor = rotate_b_bias_factor;
			ctx->big_element_bias_factor = big_element_bias_factor;
			simulate_insert_chunk(ctx, pushed_count);
			evaluate_bias_factors(ctx, rotate_b_bias_factor, big_element_bias_factor, ctx->best_rotate_a_bias_factor);
			restore_stacks(ctx);
			restore_info(ctx);
			big_element_bias_factor += 0.2;
		}
		rotate_b_bias_factor += 0.1;
	}
}

void	third_grid_search_rotate_b(t_ctx *ctx, int pushed_count)
{
	double rotate_b_bias_factor;
	double big_element_bias_factor;

	rotate_b_bias_factor = ctx->best_rotate_b_bias_factor - 0.09;
	while (rotate_b_bias_factor <= ctx->best_rotate_b_bias_factor + 0.09) 
	{
		if (rotate_b_bias_factor == ctx->best_rotate_b_bias_factor)
			rotate_b_bias_factor += 0.01;
		big_element_bias_factor = 0.0;
		while (big_element_bias_factor <= 5.0)
		{
			// if (!(ctx->rotate_b_bias_factor >= ctx->grid_search_slope * ctx->big_element_bias_factor - 3.0))
			// 	break ;
			// if (!(ctx->rotate_b_bias_factor <= ctx->grid_search_slope * ctx->big_element_bias_factor + 3.5))
			// {
			// 	ctx->big_element_bias_factor += 0.2;
			// 	continue;
			// }
			ctx->rotate_b_bias_factor = rotate_b_bias_factor;
			ctx->big_element_bias_factor = big_element_bias_factor;
			simulate_insert_chunk(ctx, pushed_count);
			evaluate_bias_factors(ctx, rotate_b_bias_factor, big_element_bias_factor, ctx->best_rotate_a_bias_factor);
			restore_stacks(ctx);
			restore_info(ctx);
			big_element_bias_factor += 0.2;
		}
		rotate_b_bias_factor += 0.01;
	}
}
