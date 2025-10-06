/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:58:12 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_pa(t_ctx *ctx)
{
	t_element	*element;

	element = *(ctx->stack_a);
	if (element == element->next)
		*(ctx->stack_a) = NULL;
	else
	{
		*(ctx->stack_a) = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ps_lstadd_front(ctx->stack_b, element);
}

void	restore_sb(t_element **stack_b)
{
	t_element	*first;
	t_element	*second;

	first = *stack_b;
	second = (*stack_b)->next;
	if (second->next == first) {
		*stack_b = second;
		return ;
	}
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack_b = second;
}

void	restore_rotate_order(t_ctx *ctx, t_order *order_node)
{
	while (order_node->ra > 0)
	{
		*(ctx->stack_a) = (*(ctx->stack_a))->prev;
		order_node->ra--;
	}
	while (order_node->rra > 0)
	{
		*(ctx->stack_a) = (*(ctx->stack_a))->next;
		order_node->rra--;
	}
	while (order_node->rb > 0)
	{
		*(ctx->stack_b) = (*(ctx->stack_b))->prev;
		order_node->rb--;
	}
	while (order_node->rrb > 0)
	{
		*(ctx->stack_b) = (*(ctx->stack_b))->next;
		order_node->rrb--;
	}
	while (order_node->rr > 0)
	{
		*(ctx->stack_a) = (*(ctx->stack_a))->prev;
		*(ctx->stack_b) = (*(ctx->stack_b))->prev;
		order_node->rr--;
	}
	while (order_node->rrr > 0)
	{
		*(ctx->stack_a) = (*(ctx->stack_a))->next;
		*(ctx->stack_b) = (*(ctx->stack_b))->next;
		order_node->rrr--;
	}
}
