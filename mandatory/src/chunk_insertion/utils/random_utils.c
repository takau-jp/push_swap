/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:32:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 04:50:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_random_seed(t_ctx *ctx)
{
	ctx->random_seed = (uint32_t)0x12345678;
}

double	range_random(t_ctx *ctx, double min, double max)
{
	double	random;

	random = (double)(ft_xorshift(&(ctx->random_seed))) / (double)UINT32_MAX;
	return (min + (max - min) * random);
}
