/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_unsorted_elements_case_0xx4x.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:19:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:24:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_unsorted_elements_case_0xx4x(t_ctx *ctx)
{
	t_element	*zero;

	zero = ctx->rank[0];
	if (zero->next->rank == 3 && zero->prev->rank == 2)
		case_03142(ctx, ctx->stack_a.top);
	if (zero->next->rank == 3 && zero->prev->rank == 1)
		case_03241(ctx);
	if (zero->next->rank == 2 && zero->prev->rank == 3)
		case_02143(ctx);
}

void	case_03142(t_ctx *ctx, t_element *top)
{
	if (top->rank == 0 || top->rank == 3 || top->rank == 2)
	{
		rotate_a_to_rank(ctx, 0);
		execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, pa, ra, ra, pa, NULL});
	}
	else
	{
		rotate_a_to_rank(ctx, 1);
		execute_orders(ctx, \
			(t_order_func []){pb, ra, pb, ra, pa, pa, rra, NULL});
	}
}

void	case_03241(t_ctx *ctx)
{
	rotate_a_to_rank(ctx, 0);
	execute_orders(ctx, \
			(t_order_func []){pb, sa, rra, pa, NULL});
}

void	case_02143(t_ctx *ctx)
{
	rotate_a_to_rank(ctx, 1);
	execute_orders(ctx, \
			(t_order_func []){pb, sa, rra, pa, rra, NULL});
}
