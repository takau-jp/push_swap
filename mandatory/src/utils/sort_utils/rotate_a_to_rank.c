/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_to_rank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:09:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:25:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_rank(t_ctx *ctx, int64_t target_rank)
{
	int64_t	up_rotation_cost;
	int64_t	down_rotation_cost;

	up_rotation_cost \
		= calc_rotation_cost(ctx->stack_a.top, target_rank, up_rotate);
	down_rotation_cost \
		= calc_rotation_cost(ctx->stack_a.top, target_rank, down_rotate);
	if (up_rotation_cost == 0)
		return ;
	if (up_rotation_cost <= down_rotation_cost)
		execute_orders_rotate(ctx, up_rotation_cost, ra);
	else
		execute_orders_rotate(ctx, down_rotation_cost, rra);
}
