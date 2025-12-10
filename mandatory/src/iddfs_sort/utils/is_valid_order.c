/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:03:55 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:33:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_invalid_order(t_ctx *ctx, t_order_type order_type);
bool	is_replcaceable_order_rotate(t_ctx *ctx, t_order_type order_type);

bool	is_valid_order(t_ctx *ctx, t_order_type order_type)
{
	if (is_invalid_order(ctx, order_type) == true)
		return (false);
	if (is_replcaceable_order_rotate(ctx, order_type) == true)
		return (false);
	return (true);
}

bool	is_invalid_order(t_ctx *ctx, t_order_type order_type)
{
	if (order_type == RA || order_type == RRA || order_type == SA)
	{
		if (ctx->stack_a.size < 2)
			return (true);
	}
	else if (order_type == RB || order_type == RRB || order_type == SB)
	{
		if (ctx->stack_b.size < 2)
			return (true);
	}
	else if (order_type == RR || order_type == RRR || order_type == SS)
	{
		if (ctx->stack_a.size < 2 || ctx->stack_b.size < 2)
			return (true);
	}
	else if (order_type == PA && ctx->stack_b.size == 0)
	{
		return (true);
	}
	else if (order_type == PB && ctx->stack_a.size == 0)
	{
		return (true);
	}
	return (false);
}

bool	is_replcaceable_order_rotate(t_ctx *ctx, t_order_type order_type)
{
	t_order	*current;

	current = ctx->current_order;
	if (order_type == RA \
		&& (current->rb > 0 || current->rra > 0 || current->rrr))
		return (true);
	else if (order_type == RRA \
		&& (current->rrb > 0 || current->ra > 0 || current->rr))
		return (true);
	else if (order_type == RB \
		&& (current->ra > 0 || current->rrb > 0 || current->rrr))
		return (true);
	else if (order_type == RRB \
		&& (current->rra > 0 || current->rb > 0 || current->rr))
		return (true);
	else if (order_type == RR \
		&& (current->rra > 0 || current->rrb > 0 || current->rrr))
		return (true);
	else if (order_type == RRR \
		&& (current->ra > 0 || current->rb > 0 || current->rr))
		return (true);
	return (false);
}
