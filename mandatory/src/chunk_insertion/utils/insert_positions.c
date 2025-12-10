/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:41:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:19:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	get_insert_position_rank(t_ctx *ctx, int64_t insert_rank);

void	set_insert_positions(t_ctx *ctx)
{
	int64_t	i;
	int64_t	insert_position;

	insert_position \
		= get_insert_position_rank(ctx, ctx->max_unsorted_element->rank);
	i = ctx->max_unsorted_element->rank;
	while (i >= 0)
	{
		if (ctx->rank[i]->state == SORTED)
			insert_position = i;
		else
			ctx->rank[i]->insert_position = insert_position;
		i--;
	}
}

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

void	renew_insert_positions(t_ctx *ctx, int64_t inserted_rank)
{
	int64_t	i;

	if (inserted_rank == 0)
		i = ctx->size - 1;
	else
		i = inserted_rank - 1;
	while (true)
	{
		if (ctx->rank[i]->state == SORTED)
			return ;
		ctx->rank[i]->insert_position = inserted_rank;
		i--;
		if (i == -1)
			i = ctx->size - 1;
	}
}
