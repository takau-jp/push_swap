/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:03:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:04:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_order_rotate(t_ctx *ctx, t_order_type order_type);
void	restore_order_swap(t_ctx *ctx, t_order_type order_type);
void	restore_order_push(t_ctx *ctx, t_order_type order_type);

void	restore_order(t_ctx *ctx, t_order_type order_type)
{
	if (RA <= order_type && order_type <= RRR)
		restore_order_rotate(ctx, order_type);
	else if (order_type == SA || order_type == SB || order_type == SS)
		restore_order_swap(ctx, order_type);
	else
		restore_order_push(ctx, order_type);
}

void	restore_order_rotate(t_ctx *ctx, t_order_type order_type)
{
	if (order_type == RA)
		rra(ctx);
	else if (order_type == RRA)
		ra(ctx);
	else if (order_type == RB)
		rrb(ctx);
	else if (order_type == RRB)
		rb(ctx);
	else if (order_type == RR)
		rrr(ctx);
	else if (order_type == RRR)
		rr(ctx);
}

void	restore_order_swap(t_ctx *ctx, t_order_type order_type)
{
	t_order	*prev_order;

	prev_order = ctx->current_order->prev;
	if (order_type == SA)
	{
		restore_sa(ctx);
		prev_order->sa = false;
	}
	else if (order_type == SB)
	{
		restore_sb(ctx);
		prev_order->sb = false;
	}
	else if (order_type == SS)
	{
		restore_ss(ctx);
		prev_order->ss = false;
	}
	else
		return ;
	prev_order->next = ctx->head_order;
	ctx->head_order->prev = prev_order;
	free(ctx->current_order);
	ctx->current_order = prev_order;
}

void	restore_order_push(t_ctx *ctx, t_order_type order_type)
{
	t_order	*prev_order;

	prev_order = ctx->current_order->prev;
	if (order_type == PA)
	{
		restore_pa(ctx);
		prev_order->pa = false;
	}
	else if (order_type == PB)
	{
		restore_pb(ctx);
		prev_order->pb = false;
	}
	else
		return ;
	prev_order->next = ctx->head_order;
	ctx->head_order->prev = prev_order;
	free(ctx->current_order);
	ctx->current_order = prev_order;
}
