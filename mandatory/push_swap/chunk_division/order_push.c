/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:04:46 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/27 17:32:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_push(t_ctx *ctx, t_chunk *chunk, \
			t_target_element target, t_rotate_func rotate)
{
	if (rotate == up_rotate)
		rotate_order(ctx, target.rotate_cost_a, ra);
	else
		rotate_order(ctx, target.rotate_cost_a, rra);
	pb(ctx);
	target.element->is_pushed = false;
	ctx->size_a--;
	ctx->size_b++;
	if (target.element->chunk_number != chunk->big_number)
		rb(ctx);
}
