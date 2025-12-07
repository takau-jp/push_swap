/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:48:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 02:15:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore(t_ctx *ctx)
{
	t_order	*restore_order_node;

	while (ctx->current_order->prev != ctx->restore.confirmed_order_node)
	{
		restore_order_node = ctx->current_order->prev;
		restore_pa(ctx);
		ctx->stack_b.top->state |= UNSORTED | PUSH_TARGET;
		restore_rotate_order(ctx, restore_order_node);
		restore_order_node->prev->next = restore_order_node->next;
		restore_order_node->next->prev = restore_order_node->prev;
		free(restore_order_node);
	}
	ctx->max_unsorted_element = ctx->restore.max_unsorted_element;
}
