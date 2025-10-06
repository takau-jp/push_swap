/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_to_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:46:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 03:59:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_index(t_ctx *ctx, size_t target_index)
{
	size_t	up_rotate_cost;
	size_t	down_rotate_cost;

	up_rotate_cost = calc_rotate_cost(ctx->stack_a, target_index, up_rotate);
	down_rotate_cost = calc_rotate_cost(ctx->stack_a, target_index, down_rotate);
	if (up_rotate_cost == 0)
		return ;
	if (up_rotate_cost <= down_rotate_cost)
		rotate_order(ctx, up_rotate_cost, ra);
	else
		rotate_order(ctx, down_rotate_cost, rra);
}
