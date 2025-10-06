/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grid_search_area.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:17:55 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/25 23:44:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -2 <= y <= 10
// 0 <= x <= 3
// y >= 1.5x − 2​
// y <= 1.625x+3.5​


// -1 <= y <= 10
// 0 <= x <= 3
// y >= 2.75x - 1.5
// y <= 2.5x + 3.5


void	calc_grid_search_area(t_ctx *ctx, int pushed_count)
{
	ctx->slope = 0.5 + 0.5 * (pushed_count / 10);
	ctx->min_intercept = -3;
	ctx->max_intercept = 3.5;
}