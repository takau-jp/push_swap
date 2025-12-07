/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:38:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:47:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(t_ctx *ctx, int *num_array)
{
	t_element	*node;
	int64_t		i;

	i = 0;
	while (i < ctx->size)
	{
		node = ps_stack_new(num_array[i]);
		if (node == NULL)
		{
			ps_stack_clear(ctx);
			free(num_array);
			error();
		}
		ps_stack_add_back(&(ctx->stack_a.top), node);
		i++;
	}
	ctx->stack_a.size = ctx->size;
	ctx->stack_b.top = NULL;
	ctx->stack_b.size = 0;
}
