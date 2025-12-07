/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_push_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:25:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:49:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	calc_push_cost(t_order *order, t_order *prev_order)
{
	int64_t	cost;

	cost = 0;
	cost += order->ra;
	cost += order->rra;
	cost += order->rb;
	cost += order->rrb;
	cost += order->rr;
	cost += order->rrr;
	cost += 1;
	if (prev_order->pa == true && prev_order->rb > 0 && order->rrb > 0)
		cost--;
	else if (prev_order->pb == true && prev_order->ra > 0 && order->rra > 0)
		cost--;
	return (cost);
}
