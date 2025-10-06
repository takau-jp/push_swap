/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:18:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_orders(t_order **lst)
{
	t_order	*head;
	t_order	*current;
	t_order	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	head = *lst;
	current = head->next;
	while (current != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(head);
	*lst = NULL;
}
