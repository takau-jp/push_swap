/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:38:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:32:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_stack_a(t_ctx *ctx, int *num_array)
{
	t_element	*head;
	t_element	*node;
	size_t		i;

	head = NULL;
	i = 0;
	while (i < ctx->size)
	{
		node = ps_lstnew(num_array[i]);
		if (node == NULL)
		{
			ps_lstclear(&head);
			free(num_array);
			ft_dprintf(STDERR_FILENO, "Error\n");
			exit(1);
		}
		ps_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
