/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:09:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_element **stack);

static bool	swap(t_element **stack)
{
	t_element	*first;
	t_element	*second;

	if (*stack == NULL || (*stack)->next == *stack)
		return (false);
	first = *stack;
	second = (*stack)->next;
	if (second->next == first) {
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

void	sa(t_ctx *ctx)
{
	if (swap(ctx->stack_a))
		add_order(ctx, "sa");
}

void	sb(t_ctx *ctx)
{
	if (swap(ctx->stack_b))
		add_order(ctx, "sb");
}

void	ss(t_ctx *ctx)
{
	if (swap(ctx->stack_a))
	{
		if (swap(ctx->stack_b))
		{
			add_order(ctx, "ss");
			return ;
		}
		add_order(ctx, "sa");
		return ;
	}
	else if (swap(ctx->stack_b))
		add_order(ctx, "sb");
}

