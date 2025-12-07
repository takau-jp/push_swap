/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_search_area.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:17:55 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 10:24:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_rotate_b_max(t_ctx *ctx);
void	calc_rotate_b_min(t_ctx *ctx);
void	calc_big_element_max(t_ctx *ctx);
void	calc_big_element_min(t_ctx *ctx);

void	calc_search_area(t_ctx *ctx)
{
	double	abs_rotate_b;
	double	abs_big_element;

	calc_rotate_b_max(ctx);
	calc_rotate_b_min(ctx);
	calc_big_element_max(ctx);
	calc_big_element_min(ctx);
	abs_rotate_b = ctx->search_area.max_rotate_b \
						+ ft_fabs(ctx->search_area.min_rotate_b);
	abs_big_element = ctx->search_area.max_big_element \
						+ ft_fabs(ctx->search_area.min_big_element);
	ctx->search_area.random_search_count \
		= (int)(abs_rotate_b * abs_big_element);
}

void	calc_rotate_b_max(t_ctx *ctx)
{
	if (ctx->chunk_size > 100)
		ctx->search_area.max_rotate_b = 10.0;
	else if (ctx->chunk_size > 80)
		ctx->search_area.max_rotate_b = 20.0;
	else if (ctx->chunk_size > 40)
		ctx->search_area.max_rotate_b = 25.0;
	else if (ctx->chunk_size > 20)
		ctx->search_area.max_rotate_b = 30.0;
	else
		ctx->search_area.max_rotate_b = 20.0;
}

void	calc_rotate_b_min(t_ctx *ctx)
{
	if (ctx->chunk_size > 20)
		ctx->search_area.min_rotate_b = -5.0;
	else
		ctx->search_area.min_rotate_b = -30.0;
}

void	calc_big_element_max(t_ctx *ctx)
{
	if (ctx->chunk_size > 80)
		ctx->search_area.max_big_element = 5.0;
	else if (ctx->chunk_size > 40)
		ctx->search_area.max_big_element = 10.0;
	else if (ctx->chunk_size > 20)
		ctx->search_area.max_big_element = 15.0;
	else
		ctx->search_area.max_big_element = 30.0;
}

void	calc_big_element_min(t_ctx *ctx)
{
	ctx->search_area.min_big_element = 0;
}
