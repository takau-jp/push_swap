/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:12:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 12:03:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_add_front(t_element **stack, t_element *new)
{
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	*stack = new;
}
