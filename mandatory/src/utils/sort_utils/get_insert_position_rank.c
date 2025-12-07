/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:10:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 14:59:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	get_insert_position_rank(t_ctx *ctx, int64_t insert_rank)
{
	int64_t	target_rank;

	target_rank = insert_rank;
	while (ctx->rank[target_rank]->state & UNSORTED)
	{
		if (target_rank == ctx->size - 1)
			target_rank = 0;
		else
			target_rank++;
	}
	return (target_rank);
}
