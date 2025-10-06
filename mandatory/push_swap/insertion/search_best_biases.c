/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_best_biases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:02:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/03 22:06:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_best_biases(t_ctx *ctx, int pushed_count)
{
	*(ctx->save_order_node) = (*(ctx->current_order))->prev;
	set_restore_info(ctx);
	calc_grid_search_area(ctx, pushed_count);
	first_grid_search_rotate_b(ctx, pushed_count);
	second_grid_search_rotate_b(ctx, pushed_count);
	third_grid_search_rotate_b(ctx, pushed_count);
	ctx->rotate_b_bias_factor = ctx->best_rotate_b_bias_factor;
	grid_search_big_element(ctx, pushed_count);
	ctx->big_element_bias_factor = ctx->best_big_element_bias_factor;
	// printf("%.2lf,%.2lf\n", ctx->best_rotate_b_bias_factor, ctx->best_big_element_bias_factor);
}

