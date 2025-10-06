/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:04:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:12:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstclear(t_element **lst)
{
	t_element	*head;
	t_element	*current;
	t_element	*next;

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
