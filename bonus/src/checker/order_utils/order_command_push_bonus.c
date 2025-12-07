/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_push_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/04 00:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_ctx *ctx)
{
	t_element	*element;

	if (ctx->stack_b.top == NULL)
		return ;
	element = ctx->stack_b.top;
	if (element == element->next)
		ctx->stack_b.top = NULL;
	else
	{
		ctx->stack_b.top = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ctx->stack_a.size++;
	ctx->stack_b.size--;
	ps_stack_add_front(&ctx->stack_a.top, element);
}

void	pb(t_ctx *ctx)
{
	t_element	*element;

	if (ctx->stack_a.top == NULL)
		return ;
	element = ctx->stack_a.top;
	if (element == element->next)
		ctx->stack_a.top = NULL;
	else
	{
		ctx->stack_a.top = element->next;
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	ctx->stack_a.size--;
	ctx->stack_b.size++;
	ps_stack_add_front(&ctx->stack_b.top, element);
}
