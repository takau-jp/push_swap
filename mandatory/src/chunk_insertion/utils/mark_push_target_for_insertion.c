/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_push_target_for_insertion.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:53:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:05:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mark_push_target_for_insertion(t_ctx *ctx, int chunk_number)
{
	int		chunk_size;
	int64_t	i;

	i = ctx->unsorted_count - 1;
	chunk_size = 0;
	while (true)
	{
		if (ctx->unsorted_rank[i]->chunk_number == chunk_number)
		{
			ctx->unsorted_rank[i]->state |= PUSH_TARGET;
			ctx->min_chunk_element = ctx->unsorted_rank[i];
			chunk_size++;
		}
		if (i == 0)
			break ;
		i--;
	}
	return (chunk_size);
}
