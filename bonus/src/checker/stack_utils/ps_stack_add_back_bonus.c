/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_add_back_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:13:07 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 14:16:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ps_stack_add_back(t_element **stack, t_element *new)
{
	t_element	*head;
	t_element	*last;

	if (!stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	head = *stack;
	last = (*stack)->prev;
	new->prev = last;
	new->next = head;
	last->next = new;
	head->prev = new;
}
