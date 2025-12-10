/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:01:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:47:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_lis_info(t_ctx *ctx, t_lis *lis)
{
	lis->seq = (int64_t *)malloc(sizeof(int64_t) * ctx->size);
	lis->tails = (int64_t *)malloc(sizeof(int64_t) * ctx->size);
	lis->prev = (int64_t *)malloc(sizeof(int64_t) * ctx->size);
	if (lis->seq == NULL || lis->tails == NULL || lis->prev == NULL)
	{
		free(lis->seq);
		free(lis->tails);
		free(lis->prev);
		clear_context(ctx);
		error();
	}
	reset_tails(*lis, ctx->size);
	lis->len = 0;
}

void	reset_tails(t_lis lis, int64_t len)
{
	int64_t	i;

	i = 0;
	while (i < len)
	{
		lis.tails[i] = LIS_INIT;
		i++;
	}
}
