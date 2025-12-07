/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_unsorted_elements_case_0x4xx.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:19:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:26:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_unsorted_elements_case_0x4xx(t_ctx *ctx)
{
	t_element	*zero;

	zero = ctx->rank[0];
	if (zero->next->rank == 1 && zero->prev->rank == 2)
		case_01432(ctx, ctx->stack_a.top);
	if (zero->next->rank == 2 && zero->prev->rank == 3)
		case_02413(ctx, ctx->stack_a.top);
	if (zero->next->rank == 2 && zero->prev->rank == 1)
		case_02431(ctx, ctx->stack_a.top);
	if (zero->next->rank == 3 && zero->prev->rank == 1)
		case_03421(ctx);
}

void	case_01432(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0 || top->rank == 1 || top->rank == 2)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, rra, pa, pa, NULL});
	}
	else if (top->rank == 4 || top->rank == 3)
	{
		rotate_a_to_rank(ctx, 4);
		execute_orders(ctx, \
			(t_order_func []){pb, sa, ra, ra, pa, ra, NULL});
	}
}

void	case_02413(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0 || top->rank == 2 || top->rank == 3)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, rra, pa, rra, pa, NULL});
	}
	else if (top->rank == 4 || top->rank == 1)
	{
		rotate_a_to_rank(ctx, 4);
		execute_orders(ctx, \
			(t_order_func []){pb, sa, ra, sa, pa, ra, NULL});
	}
}

void	case_02431(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0 || top->rank == 1)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, pa, rra, pa, NULL});
	}
	else if (top->rank == 4 || top->rank == 3 || top->rank == 2)
	{
		rotate_a_to_rank(ctx, 4);
		execute_orders(ctx, \
			(t_order_func []){pb, ra, sa, pa, ra, NULL});
	}
}

void	case_03421(t_ctx *ctx)
{
	rotate_a_to_rank(ctx, 0);
	execute_orders(ctx, \
			(t_order_func []){pb, rra, rra, sa, pa, NULL});
}
