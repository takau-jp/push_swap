/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/04 00:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *ctx)
{
	if (ctx->stack_a.size <= 1)
		return ;
	ctx->stack_a.top = ctx->stack_a.top->next;
	add_order(ctx, "ra");
}

void	rb(t_ctx *ctx)
{
	if (ctx->stack_b.size <= 1)
		return ;
	ctx->stack_b.top = ctx->stack_b.top->next;
	add_order(ctx, "rb");
}

void	rr(t_ctx *ctx)
{
	if (ctx->stack_a.top != NULL)
	{
		if (ctx->stack_b.top != NULL)
		{
			ctx->stack_a.top = ctx->stack_a.top->next;
			ctx->stack_b.top = ctx->stack_b.top->next;
			add_order(ctx, "rr");
		}
		else
		{
			ctx->stack_a.top = ctx->stack_a.top->next;
			add_order(ctx, "ra");
		}
	}
	else if (ctx->stack_b.top != NULL)
	{
		ctx->stack_b.top = ctx->stack_b.top->next;
		add_order(ctx, "rb");
	}
}
