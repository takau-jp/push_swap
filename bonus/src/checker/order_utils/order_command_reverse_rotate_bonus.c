/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_reverse_rotate_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/04 00:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_ctx *ctx)
{
	if (ctx->stack_a.size <= 1)
		return ;
	ctx->stack_a.top = ctx->stack_a.top->prev;
}

void	rrb(t_ctx *ctx)
{
	if (ctx->stack_b.size <= 1)
		return ;
	ctx->stack_b.top = ctx->stack_b.top->prev;
}

void	rrr(t_ctx *ctx)
{
	if (ctx->stack_a.top != NULL)
	{
		if (ctx->stack_b.top != NULL)
		{
			ctx->stack_a.top = ctx->stack_a.top->prev;
			ctx->stack_b.top = ctx->stack_b.top->prev;
		}
		else
		{
			ctx->stack_a.top = ctx->stack_a.top->prev;
		}
	}
	else if (ctx->stack_b.top != NULL)
	{
		ctx->stack_b.top = ctx->stack_b.top->prev;
	}
}
