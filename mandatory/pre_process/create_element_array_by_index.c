/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element_array_by_index.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_element_array_by_index(t_ctx *ctx)
{
	t_element	*element;
	size_t		i;

	ctx->elements_by_index \
		= (t_element **)malloc(sizeof(t_element *) * ctx->size);
	if (ctx->elements_by_index == NULL)
	{
		exit(1); //error
	}
	element = *(ctx->stack_a);
	i = 0;
	while (i < ctx->size)
	{
		ctx->elements_by_index[element->index] = element;
		element = element->next;
		i++;
	}
}
