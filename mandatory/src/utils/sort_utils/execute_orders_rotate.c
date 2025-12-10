/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_orders_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 05:25:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:17:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_orders_rotate(t_ctx *ctx, \
	int64_t rotation_cost, t_order_func rotate_order)
{
	while (rotation_cost > 0)
	{
		rotate_order(ctx);
		rotation_cost--;
	}
}
