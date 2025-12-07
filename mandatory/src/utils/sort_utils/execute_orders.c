/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 05:25:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 05:29:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotate_orders(t_ctx *ctx, \
	int64_t rotation_cost, t_order_func rotate_order)
{
	while (rotation_cost > 0)
	{
		rotate_order(ctx);
		rotation_cost--;
	}
}

void	execute_orders(t_ctx *ctx, t_order_func orders[])
{
	int64_t	i;

	i = 0;
	while (orders[i] != NULL)
	{
		orders[i](ctx);
		i++;
	}
}
