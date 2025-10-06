/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:10:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 14:59:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_insert_position_index(t_ctx *ctx, size_t insert_index)
{
	size_t	target_index;

	target_index = insert_index;
	while (ctx->elements_by_index[target_index]->is_unsorted == true)
	{
		if (target_index == ctx->size - 1)
			target_index = 0;
		else
			target_index++;
	}
	return (target_index);
}

void	get_max_pushed_element_index(t_ctx *ctx)
{
	size_t	i;

	i = ctx->size - 1;
	while (true)
	{
		if (ctx->elements_by_index[i]->is_pushed == true)
		{
			ctx->max_pushed_element_index = i;
			return ;
		}
		i--;
	}
}

void	get_min_chunk_element_index(t_ctx *ctx)
{
	size_t	i;

	i = 0;
	while (true)
	{
		if (ctx->elements_by_index[i]->is_pushed == true)
		{
			ctx->min_chunk_element_index = i;
			return ;
		}
		i++;
	}
}
