/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:09:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 01:13:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_element **stack);

void	sa(t_ctx *ctx)
{
	if (swap(&(ctx->stack_a.top)))
		add_order(ctx, "sa");
}

void	sb(t_ctx *ctx)
{
	if (swap(&(ctx->stack_b.top)))
		add_order(ctx, "sb");
}

void	ss(t_ctx *ctx)
{
	if (swap(&(ctx->stack_a.top)))
	{
		if (swap(&(ctx->stack_b.top)))
		{
			add_order(ctx, "ss");
			return ;
		}
		add_order(ctx, "sa");
		return ;
	}
	else if (swap(&(ctx->stack_b.top)))
		add_order(ctx, "sb");
}

static bool	swap(t_element **stack)
{
	t_element	*first;
	t_element	*second;

	if (*stack == NULL || (*stack)->next == *stack)
		return (false);
	first = *stack;
	second = (*stack)->next;
	if (second->next == first)
	{
		*stack = second;
		return (true);
	}
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
	return (true);
}
