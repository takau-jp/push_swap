/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_chunk_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:01:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:57:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_chunk_number(t_ctx *ctx)
{
	int		chunk_number;
	int		chunk_size;
	int64_t	i;
	int		count;

	chunk_number = 0;
	i = 0;
	while (chunk_number < ctx->chunk_count)
	{
		chunk_size = ctx->unsorted_count / ctx->chunk_count;
		if (chunk_number < (int)(ctx->unsorted_count % ctx->chunk_count))
			chunk_size++;
		count = 0;
		while (count < chunk_size)
		{
			if (ctx->unsorted_rank[i]->state & UNSORTED)
			{
				ctx->unsorted_rank[i]->chunk_number = chunk_number;
				count++;
			}
			i++;
		}
		chunk_number++;
	}
}
