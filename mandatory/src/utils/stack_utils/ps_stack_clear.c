/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:11:36 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:09:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack(t_element **stack);

void	ps_stack_clear(t_ctx *ctx)
{
	clear_stack(&(ctx->stack_a.top));
	clear_stack(&(ctx->stack_b.top));
}

static void	clear_stack(t_element **stack)
{
	t_element	*head;
	t_element	*current;
	t_element	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	head = *stack;
	current = head->next;
	while (current != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(head);
	*stack = NULL;
}
