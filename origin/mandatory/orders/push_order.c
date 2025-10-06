/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ctx *ctx)
{
	t_element	*element;

	if (*(ctx->stack_b) == NULL)
		return ;
	element = *(ctx->stack_b);
	if (element == element->next)
		*(ctx->stack_b) = NULL;
	else
	{
		*(ctx->stack_b) = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ps_lstadd_front(ctx->stack_a, element);
	add_order(ctx, "pa");
}

void	pb(t_ctx *ctx)
{
	t_element	*element;

	if (*(ctx->stack_a) == NULL)
		return ;
	element = *(ctx->stack_a);
	if (element == element->next)
		*(ctx->stack_a) = NULL;
	else
	{
		*(ctx->stack_a) = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ps_lstadd_front(ctx->stack_b, element);
	add_order(ctx, "pb");
}
