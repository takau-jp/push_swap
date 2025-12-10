/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rank_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:07:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:46:50 by stanaka2         ###   ########.fr       */
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
		clear_context(ctx);
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
