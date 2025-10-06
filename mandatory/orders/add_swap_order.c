/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_swap_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:12:56 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/05 23:25:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_sa(t_ctx *ctx)
{
	(*(ctx->current_order))->sa = true;
	add_new_order_node(ctx);
}

void	add_sb(t_ctx *ctx)
{
	(*(ctx->current_order))->sb = true;
	add_new_order_node(ctx);
}

void	add_ss(t_ctx *ctx)
{
	(*(ctx->current_order))->ss = true;
	add_new_order_node(ctx);
}