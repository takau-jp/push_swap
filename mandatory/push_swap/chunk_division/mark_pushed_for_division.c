/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_pushed_for_division.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:16:26 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:18:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_pushed_for_division_big_chunk(t_ctx *ctx, t_chunk *chunk)
{
	t_element	*element;
	size_t		i;

	chunk->pushed_count_in_big = 0;
	element = *(ctx->stack_a);
	i = 0;
	while (i < ctx->size_a)
	{
		if (element->is_unsorted == true)
		{
			if (element->chunk_number == chunk->big_number)
			{
				element->is_pushed = true;
				chunk->pushed_count_in_big++;
			}
		}
		element = element->next;
		i++;
	}
	chunk->big_chunk_size = chunk->pushed_count_in_big;
}


void	mark_pushed_for_division_small_chunk(t_ctx *ctx, t_chunk *chunk)
{
	t_element	*element;
	size_t		i;

	chunk->pushed_count_in_small = 0;
	element = *(ctx->stack_a);
	i = 0;
	while (i < ctx->size_a)
	{
		if (element->is_unsorted == true)
		{
			if (element->chunk_number == chunk->small_number)
			{
				element->is_pushed = true;
				chunk->pushed_count_in_small++;
			}
		}
		element = element->next;
		i++;
	}
	chunk->small_chunk_size = chunk->pushed_count_in_small;
}