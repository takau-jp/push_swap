/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ctx *ctx)
{
	if (ctx->size_a <= 1)
		return ;
	*(ctx->stack_a) = (*(ctx->stack_a))->prev;
	add_order(ctx, "rra");
}

void	rrb(t_ctx *ctx)
{
	if (ctx->size_b <= 1)
		return ;
	*(ctx->stack_b) = (*(ctx->stack_b))->prev;
	add_order(ctx, "rrb");
}

void	rrr(t_ctx *ctx)
{
	if (*(ctx->stack_a) != NULL)
	{
		if (*(ctx->stack_b) != NULL)
		{
			*(ctx->stack_a) = (*(ctx->stack_a))->prev;
			*(ctx->stack_b) = (*(ctx->stack_b))->prev;
			add_order(ctx, "rrr");
		}
		else
		{
			*(ctx->stack_a) = (*(ctx->stack_a))->prev;
			add_order(ctx, "rra");
		}
	}
	else if (*(ctx->stack_b) != NULL)
	{
		*(ctx->stack_b) = (*(ctx->stack_b))->prev;
		add_order(ctx, "rrb");
	}
}
