/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:18:10 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_unsorted(t_ctx *ctx, size_t *lis)
{
	size_t		i;

	i = 0;
	while (i < ctx->size)
	{
		ctx->elements_by_index[i]->is_unsorted = true;
		i++;
	}
	i = 0;
	while (i < ctx->lis_length)
	{
		ctx->elements_by_index[lis[i]]->is_unsorted = false;
		i++;
	}
}
