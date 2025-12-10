/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_push_target_for_division.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:06:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:05:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	renew_push_target(t_ctx *ctx, t_chunk *big_chunk, t_chunk *small_chunk)
{
	while (big_chunk->number != ctx->chunk_count && big_chunk->count == 0)
	{
		big_chunk->number++;
		if (big_chunk->number == ctx->chunk_count)
			break ;
		mark_push_target_for_division(ctx, big_chunk);
	}
	while (small_chunk->number != -1 && small_chunk->count == 0)
	{
		small_chunk->number--;
		if (small_chunk->number == -1)
			break ;
		mark_push_target_for_division(ctx, small_chunk);
	}
}

void	mark_push_target_for_division(t_ctx *ctx, t_chunk *chunk)
{
	int64_t	i;

	chunk->count = 0;
	i = 0;
	while (i < ctx->unsorted_count \
			&& ctx->unsorted_rank[i]->chunk_number != chunk->number)
		i++;
	while (i < ctx->unsorted_count \
			&& ctx->unsorted_rank[i]->chunk_number == chunk->number)
	{
		ctx->unsorted_rank[i]->state |= PUSH_TARGET;
		chunk->count++;
		i++;
	}
}
