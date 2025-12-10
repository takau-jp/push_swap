/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_reverse_rotate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:07:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ctx *ctx)
{
	if (ctx->stack_a.size <= 1)
		return ;
	ctx->stack_a.top = ctx->stack_a.top->prev;
	add_order(ctx, "rra");
}

void	rrb(t_ctx *ctx)
{
	if (ctx->stack_b.size <= 1)
		return ;
	ctx->stack_b.top = ctx->stack_b.top->prev;
	add_order(ctx, "rrb");
}

void	rrr(t_ctx *ctx)
{
	if (ctx->stack_a.top != NULL)
	{
		if (ctx->stack_b.top != NULL)
		{
			ctx->stack_a.top = ctx->stack_a.top->prev;
			ctx->stack_b.top = ctx->stack_b.top->prev;
			add_order(ctx, "rrr");
		}
		else
		{
			ctx->stack_a.top = ctx->stack_a.top->prev;
			add_order(ctx, "rra");
		}
	}
	else if (ctx->stack_b.top != NULL)
	{
		ctx->stack_b.top = ctx->stack_b.top->prev;
		add_order(ctx, "rrb");
	}
}
