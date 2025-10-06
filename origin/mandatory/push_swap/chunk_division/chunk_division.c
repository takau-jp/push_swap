/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_division.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:45:40 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/26 00:08:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_chunk_number_and_index_in_chunk(t_ctx *ctx, size_t data_size);
void	divide_chunk(t_ctx *ctx);

void	chunk_division(t_ctx *ctx)
{
	size_t	data_size;

	data_size = ctx->unsorted_count;
	ctx->chunk_count \
		= (int)ft_round(ft_sqrt((double)data_size) / CHUNK_DIVISION_FACTOR);
	if (ctx->chunk_count == 0)
		ctx->chunk_count = 1;
	calc_chunk_number_and_index_in_chunk(ctx, data_size);
	divide_chunk(ctx);
}

void	calc_chunk_number_and_index_in_chunk(t_ctx *ctx, size_t data_size)
{
	int		chunk_number;
	int		chunk_size;
	size_t	i;
	int		index_in_chunk;

	chunk_number = 0;
	i = 0;
	while (chunk_number < ctx->chunk_count)
	{
		chunk_size = data_size / ctx->chunk_count;
		if (chunk_number < (int)(data_size % ctx->chunk_count))
			chunk_size++;
		index_in_chunk = 0;
		while (index_in_chunk < chunk_size)
		{
			if (ctx->elements_by_index[i]->is_unsorted == true)
			{
				ctx->elements_by_index[i]->chunk_number = chunk_number;
				ctx->elements_by_index[i]->index_in_chunk = index_in_chunk;
				index_in_chunk++;
			}
			i++;
		}
		chunk_number++;
	}
}

void	divide_chunk(t_ctx *ctx)
{
	t_chunk				chunk;
	t_efficient_rotate	rotation;

	chunk.is_end = false;
	chunk.big_number = ctx->chunk_count / 2;
	chunk.small_number = ctx->chunk_count / 2 - 1;
	if (ctx->chunk_count == 1)
		chunk.small_number = 0;
	mark_pushed_for_division_big_chunk(ctx, &chunk);
	mark_pushed_for_division_small_chunk(ctx, &chunk);
	while (chunk.is_end == false)
	{
		rotation = efficient_rotate(ctx, &chunk);
		if (rotation.is_up_rotation_start == true)
			push_chunk(ctx, &chunk, rotation, up_rotate);
		else
			push_chunk(ctx, &chunk, rotation, down_rotate);
	}
}
