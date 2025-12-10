/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:48:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:55:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_orders_rotate(t_ctx *ctx, t_order *order_node);

void	restore(t_ctx *ctx)
{
	t_order	*restore_order_node;

	while (ctx->current_order->prev != ctx->restore.confirmed_order_node)
	{
		restore_order_node = ctx->current_order->prev;
		restore_pa(ctx);
		ctx->stack_b.top->state |= UNSORTED | PUSH_TARGET;
		restore_orders_rotate(ctx, restore_order_node);
		restore_order_node->prev->next = restore_order_node->next;
		restore_order_node->next->prev = restore_order_node->prev;
		free(restore_order_node);
	}
	ctx->cost = ctx->restore.cost;
	ctx->max_unsorted_element = ctx->restore.max_unsorted_element;
}

void	restore_orders_rotate(t_ctx *ctx, t_order *order_node)
{
	while (order_node->ra-- > 0)
		ctx->stack_a.top = ctx->stack_a.top->prev;
	while (order_node->rra-- > 0)
		ctx->stack_a.top = ctx->stack_a.top->next;
	while (order_node->rb-- > 0)
		ctx->stack_b.top = ctx->stack_b.top->prev;
	while (order_node->rrb-- > 0)
		ctx->stack_b.top = ctx->stack_b.top->next;
	while (order_node->rr-- > 0)
	{
		ctx->stack_a.top = ctx->stack_a.top->prev;
		ctx->stack_b.top = ctx->stack_b.top->prev;
	}
	while (order_node->rrr-- > 0)
	{
		ctx->stack_a.top = ctx->stack_a.top->next;
		ctx->stack_b.top = ctx->stack_b.top->next;
	}
}
