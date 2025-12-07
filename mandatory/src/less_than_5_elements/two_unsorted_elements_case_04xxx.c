/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_unsorted_elements_case_04xxx.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:19:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 05:43:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_unsorted_elements_case_04xxx(t_ctx *ctx)
{
	t_element	*zero;

	zero = ctx->rank[0];
	if (zero->next->next->rank == 3 && zero->prev->rank == 2)
		case_04312(ctx);
	if (zero->next->next->rank == 2 && zero->prev->rank == 3)
		case_04213(ctx, ctx->stack_a.top);
	if (zero->next->next->rank == 2 && zero->prev->rank == 1)
		case_04231(ctx, ctx->stack_a.top);
	if (zero->next->next->rank == 1 && zero->prev->rank == 2)
		case_04132(ctx, ctx->stack_a.top);
}

void	case_04312(t_ctx *ctx)
{
	rotate_a_to_rank(ctx, 0);
	execute_orders(ctx, \
		(t_order_func []){pb, sa, ra, ra, pa, NULL});
}

void	case_04213(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0 || top->rank == 4 || top->rank == 3)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, ss, pa, pa, ra, NULL});
	}
	else if (top->rank == 2)
	{
		execute_orders(ctx, \
			(t_order_func []){pb, pb, ss, ra, pa, pa, rra, NULL});
	}
	else if (top->rank == 1)
	{
		execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, pa, rra, pa, rra, NULL});
	}
}

void	case_04231(t_ctx *ctx, t_element *top)
{
	if (top->rank != 3)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, rrr, pa, pa, ra, NULL});
	}
	else if (top->rank == 3)
	{
		execute_orders(ctx, \
			(t_order_func []){pb, pb, ss, pa, rra, pa, rra, NULL});
	}
}

void	case_04132(t_ctx *ctx, t_element *top)
{
	if (top->rank != 3)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){sa, rra, rra, sa, rra, rra, NULL});
	}
	else if (top->rank == 3)
	{
		execute_orders(ctx, \
			(t_order_func []){sa, rra, rra, pb, rra, pa, ra, NULL});
	}
}
