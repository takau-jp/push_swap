/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_to_rank.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:46:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/23 15:36:55 by stanaka2         ###   ########.fr       */
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
		execute_rotate_orders(ctx, up_rotation_cost, ra);
	else
		execute_rotate_orders(ctx, down_rotation_cost, rra);
}
