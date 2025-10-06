/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_swap_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:12:56 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_sa(t_ctx *ctx)
{
	t_order *order_node;
	t_order	*prev_node;

	order_node = *(ctx->current_order);
	prev_node = order_node->prev;
	if (ctx->current_order != ctx->head_order && order_node->ra == 0 && order_node->rra == 0 \
		&& prev_node->sb == true)
	{
		prev_node->sb = false;
		prev_node->ss = true;
	}
	else
	{
		order_node->sa = true;
		add_new_order_node(ctx);
	}
}

void	add_sb(t_ctx *ctx)
{
	t_order *order_node;
	t_order	*prev_node;

	order_node = *(ctx->current_order);
	prev_node = order_node->prev;
	if (ctx->current_order != ctx->head_order && order_node->rb == 0 && order_node->rrb == 0 \
		&& prev_node->sa == true)
	{
		prev_node->sa = false;
		prev_node->ss = true;
	}
	else
	{
		order_node->sb = true;
		add_new_order_node(ctx);
	}
}

void	add_ss(t_ctx *ctx)
{
	t_order *order_node;

	order_node = *(ctx->current_order);
	order_node->ss = true;
	add_new_order_node(ctx);
}