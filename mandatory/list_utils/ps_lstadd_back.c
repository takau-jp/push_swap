/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 00:04:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:12:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_element **lst, t_element *new)
{
	t_element	*head;
	t_element	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	head = *lst;
	last = (*lst)->prev;
	new->prev = last;
	new->next = head;
	last->next = new;
	head->prev = new;
}
