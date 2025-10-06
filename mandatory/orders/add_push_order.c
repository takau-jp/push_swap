/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_push_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:16:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_pa(t_ctx *ctx)
{
	(*(ctx->current_order))->pa = true;
	add_new_order_node(ctx);
}

void	add_pb(t_ctx *ctx)
{
	(*(ctx->current_order))->pb = true;
	add_new_order_node(ctx);
}
