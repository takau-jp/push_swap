/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:12:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *ctx)
{
	if (ctx->size_a <= 1)
		return ;
	*(ctx->stack_a) = (*(ctx->stack_a))->next;
	add_order(ctx, "ra");
}

void	rb(t_ctx *ctx)
{
	if (ctx->size_b <= 1)
		return ;
	*(ctx->stack_b) = (*(ctx->stack_b))->next;
	add_order(ctx, "rb");
}

void	rr(t_ctx *ctx)
{
	if (*(ctx->stack_a) != NULL)
	{
		if (*(ctx->stack_b) != NULL)
		{
			*(ctx->stack_a) = (*(ctx->stack_a))->next;
			*(ctx->stack_b) = (*(ctx->stack_b))->next;
			add_order(ctx, "rr");
		}
		else
		{
			*(ctx->stack_a) = (*(ctx->stack_a))->next;
			add_order(ctx, "ra");
		}
	}
	else if (*(ctx->stack_b) != NULL)
	{
		*(ctx->stack_b) = (*(ctx->stack_b))->next;
		add_order(ctx, "rb");
	}
}
