/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_unsorted_elements_case.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:26:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_unsorted_elements_case(t_ctx *ctx)
{
	t_element	*zero;

	zero = ctx->rank[0];
	if (ctx->size == 4)
		case_0321(ctx);
	else if (zero->next->rank == 4)
	{
		two_unsorted_elements_case_04xxx(ctx);
	}
	else if (zero->next->next->rank == 4)
	{
		two_unsorted_elements_case_0x4xx(ctx);
	}
	else if (zero->prev->prev->rank == 4)
	{
		two_unsorted_elements_case_0xx4x(ctx);
	}
	else if (zero->prev->rank == 4)
	{
		if (zero->next->rank == 3 && zero->prev->prev->rank == 1)
			case_03214(ctx, ctx->stack_a.top);
	}
}

void	case_0321(t_ctx *ctx)
{
	rotate_a_to_rank(ctx, 0);
	execute_orders(ctx, \
			(t_order_func []){pb, sa, rra, NULL});
}

void	case_03214(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0)
	{
		execute_orders(ctx, \
			(t_order_func []){sa, rra, sa, rra, rra, sa, rra, NULL});
	}
	else if (top->rank == 4)
	{
		execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, rra, pa, pa, ra, NULL});
	}
	else
	{
		rotate_a_to_rank(ctx, 2);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, rrr, pa, pa, rra, NULL});
	}
}
