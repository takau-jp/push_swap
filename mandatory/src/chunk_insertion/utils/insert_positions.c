/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:41:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 04:50:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
