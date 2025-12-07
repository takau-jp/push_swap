/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:13:58 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:50:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_unsorted_rank_array(t_ctx *ctx, t_lis lis);

void	mark_unsorted(t_ctx *ctx)
{
	t_lis		lis;
	int64_t		i;
	int64_t		unsorted_count;
	t_element	*element;

	lis = get_lis(ctx);
	allocate_unsorted_rank_array(ctx, lis);
	unsorted_count = 0;
	i = 0;
	while (i < ctx->size)
	{
		element = ctx->rank[i];
		if (i - unsorted_count < lis.len \
			&& element->rank == lis.seq[i - unsorted_count])
			element->state = SORTED;
		else
		{
			element->state = UNSORTED;
			ctx->unsorted_rank[unsorted_count] = element;
			element->unsorted_rank = unsorted_count++;
		}
		i++;
	}
	ctx->unsorted_count = unsorted_count;
	free(lis.seq);
}

void	allocate_unsorted_rank_array(t_ctx *ctx, t_lis lis)
{
	ctx->unsorted_rank \
		= (t_element **)malloc(sizeof(t_element *) * (ctx->size - lis.len));
	if (ctx->unsorted_rank == NULL)
	{
		free(lis.seq);
		free(ctx->rank);
		ps_stack_clear(ctx);
		error();
	}
}
