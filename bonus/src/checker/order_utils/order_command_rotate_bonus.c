/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_command_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/04 00:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_ctx *ctx)
{
	if (ctx->stack_a.size <= 1)
		return ;
	ctx->stack_a.top = ctx->stack_a.top->next;
}

void	rb(t_ctx *ctx)
{
	if (ctx->stack_b.size <= 1)
		return ;
	ctx->stack_b.top = ctx->stack_b.top->next;
}

void	rr(t_ctx *ctx)
{
	if (ctx->stack_a.top != NULL)
	{
		if (ctx->stack_b.top != NULL)
		{
			ctx->stack_a.top = ctx->stack_a.top->next;
			ctx->stack_b.top = ctx->stack_b.top->next;
		}
		else
		{
			ctx->stack_a.top = ctx->stack_a.top->next;
		}
	}
	else if (ctx->stack_b.top != NULL)
	{
		ctx->stack_b.top = ctx->stack_b.top->next;
	}
}
