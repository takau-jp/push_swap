/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:58:12 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 04:37:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_pa(t_ctx *ctx)
{
	t_element	*element;

	element = ctx->stack_a.top;
	if (element == element->next)
		ctx->stack_a.top = NULL;
	else
	{
		ctx->stack_a.top = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ps_stack_add_front(&(ctx->stack_b.top), element);
	ctx->stack_a.size--;
	ctx->stack_b.size++;
}

void	restore_pb(t_ctx *ctx)
{
	t_element	*element;

	element = ctx->stack_b.top;
	if (element == element->next)
		ctx->stack_b.top = NULL;
	else
	{
		ctx->stack_b.top = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ps_stack_add_front(&(ctx->stack_a.top), element);
	ctx->stack_a.size++;
	ctx->stack_b.size--;
}

void	restore_rotate_order(t_ctx *ctx, t_order *order_node)
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
