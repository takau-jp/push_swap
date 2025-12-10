/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_order_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:59:50 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:01:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_element **stack);

void	restore_sa(t_ctx *ctx)
{
	swap(&(ctx->stack_a.top));
}

void	restore_sb(t_ctx *ctx)
{
	swap(&(ctx->stack_b.top));
}

void	restore_ss(t_ctx *ctx)
{
	swap(&(ctx->stack_a.top));
	swap(&(ctx->stack_b.top));
}

bool	swap(t_element **stack)
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
