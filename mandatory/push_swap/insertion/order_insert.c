/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:42 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/27 17:35:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_insert(t_ctx *ctx, t_target_element target)
{
	if (target.is_up_rotate_a == true)
		rotate_order(ctx, target.rotate_cost_a, ra);
	else
		rotate_order(ctx, target.rotate_cost_a, rra);
	if (target.is_up_rotate_b == true)
		rotate_order(ctx, target.rotate_cost_b, rb);
	else
		rotate_order(ctx, target.rotate_cost_b, rrb);
	pa(ctx);
	target.element->is_pushed = false;
	target.element->is_unsorted = false;
	ctx->size_a++;
	ctx->size_b--;
}
