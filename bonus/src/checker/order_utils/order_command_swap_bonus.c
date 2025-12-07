/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_swap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:09:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/04 00:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	swap(t_element **stack);

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

void	sa(t_ctx *ctx)
{
	swap(&(ctx->stack_a.top));
}

void	sb(t_ctx *ctx)
{
	swap(&(ctx->stack_b.top));
}

void	ss(t_ctx *ctx)
{
	swap(&(ctx->stack_a.top));
	swap(&(ctx->stack_b.top));
}
