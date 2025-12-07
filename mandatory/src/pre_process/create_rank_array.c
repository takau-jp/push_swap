/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element_array_by_rank.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/25 22:08:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_rank_array(t_ctx *ctx)
{
	t_element	*element;
	int64_t		i;

	ctx->rank \
		= (t_element **)malloc(sizeof(t_element *) * ctx->size);
	if (ctx->rank == NULL)
	{
		ps_stack_clear(ctx);
		error();
	}
	element = ctx->stack_a.top;
	i = 0;
	while (i < ctx->size)
	{
		ctx->rank[element->rank] = element;
		element = element->next;
		i++;
	}
}
