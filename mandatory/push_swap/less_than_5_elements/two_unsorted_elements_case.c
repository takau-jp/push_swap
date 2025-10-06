/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_unsorted_elements_case.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 02:01:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// 0321

// 04312
// 04213
// 04231
// 04132

// 01432
// 02413
// 02431
// 03421

// 03142
// 03241
// 02143

// 03214

void	two_unsorted_elements_case(t_ctx *ctx)
{
	t_element *zero;

	zero = ctx->elements_by_index[0];
	if (ctx->size == 4)
		case_0321(ctx);
	else if (zero->next->index == 4)
	{
		if (zero->next->next->index == 3 && zero->prev->index == 2)
			case_04312(ctx);
		if (zero->next->next->index == 2 && zero->prev->index == 3)
			case_04213(ctx, *(ctx->stack_a));
		if (zero->next->next->index == 2 && zero->prev->index == 1)
			case_04231(ctx, *(ctx->stack_a));
		if (zero->next->next->index == 1 && zero->prev->index == 2)
			case_04132(ctx, *(ctx->stack_a));
	}
	else if (zero->next->next->index == 4)
	{
		if (zero->next->index == 1 && zero->prev->index == 2)
			case_01432(ctx, *(ctx->stack_a));
		if (zero->next->index == 2 && zero->prev->index == 3)
			case_02413(ctx, *(ctx->stack_a));
		if (zero->next->index == 2 && zero->prev->index == 1)
			case_02431(ctx, *(ctx->stack_a));
		if (zero->next->index == 3 && zero->prev->index == 1)
			case_03421(ctx);
	}
	else if (zero->prev->prev->index == 4)
	{
		if (zero->next->index == 3 && zero->prev->index == 2)
			case_03142(ctx, *(ctx->stack_a));
		if (zero->next->index == 3 && zero->prev->index == 1)
			case_03241(ctx);
		if (zero->next->index == 2 && zero->prev->index == 3)
			case_02143(ctx);
	}
	else if (zero->prev->index == 4)
	{
		if (zero->next->index == 3 && zero->prev->prev->index == 1)
			case_03214(ctx, *(ctx->stack_a));
	}
}

void	case_0321(t_ctx *ctx)
{
	rotate_a_to_index(ctx, 0);
	pb(ctx);
	sa(ctx);
	rra(ctx);
	pa(ctx);
}

void	case_04312(t_ctx *ctx)
{
	rotate_a_to_index(ctx, 0);
	pb(ctx);
	sa(ctx);
	ra(ctx);
	ra(ctx);
	pa(ctx);
}

void	case_04213(t_ctx *ctx, t_element *top)
{
	if (top->index == 0 || top->index == 4 || top->index == 3)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		ss(ctx);
		pa(ctx);
		pa(ctx);
		ra(ctx);
	}
	else if (top->index == 2)
	{
		pb(ctx);
		pb(ctx);
		ss(ctx);
		ra(ctx);
		pa(ctx);
		pa(ctx);
		rra(ctx);
	}
	else if (top->index == 1)
	{
		pb(ctx);
		pb(ctx);
		sa(ctx);
		pa(ctx);
		rra(ctx);
		pa(ctx);
		rra(ctx);
	}
}

void	case_04231(t_ctx *ctx, t_element *top)
{
	if (top->index != 3)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		rrr(ctx);
		pa(ctx);
		pa(ctx);
		ra(ctx);
	}
	else if (top->index == 3)
	{
		pb(ctx);
		pb(ctx);
		ss(ctx);
		pa(ctx);
		rra(ctx);
		pa(ctx);
		rra(ctx);
	}
}


void	case_04132(t_ctx *ctx, t_element *top)
{
	if (top->index != 3)
	{
		rotate_a_to_index(ctx, 0);
		sa(ctx);
		rra(ctx);
		rra(ctx);
		sa(ctx);
		rra(ctx);
		rra(ctx);
	}
	else if (top->index == 3)
	{
		sa(ctx);
		rra(ctx);
		rra(ctx);
		pb(ctx);
		rra(ctx);
		pa(ctx);
		ra(ctx);
	}
}

void	case_01432(t_ctx *ctx, t_element *top)
{
	if (top->index == 0 || top->index == 1 || top->index == 2)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		sa(ctx);
		rra(ctx);
		pa(ctx);
		pa(ctx);
	}
	else if (top->index == 4 || top->index == 3)
	{
		rotate_a_to_index(ctx, 4);
		pb(ctx);
		sa(ctx);
		ra(ctx);
		ra(ctx);
		pa(ctx);
		ra(ctx);
	}
}

void	case_02413(t_ctx *ctx, t_element *top)
{
	if (top->index == 0 || top->index == 2 || top->index == 3)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		rra(ctx);
		pa(ctx);
		rra(ctx);
		pa(ctx);
	}
	else if (top->index == 4 || top->index == 1)
	{
		rotate_a_to_index(ctx, 4);
		pb(ctx);
		sa(ctx);
		ra(ctx);
		sa(ctx);
		pa(ctx);
		ra(ctx);
	}
}

void	case_02431(t_ctx *ctx, t_element *top)
{
	if (top->index == 0 || top->index == 1)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		sa(ctx);
		pa(ctx);
		rra(ctx);
		pa(ctx);
	}
	else if (top->index == 4 || top->index == 3 || top->index == 2)
	{
		rotate_a_to_index(ctx, 4);
		pb(ctx);
		ra(ctx);
		sa(ctx);
		pa(ctx);
		ra(ctx);
	}
}

void	case_03421(t_ctx *ctx)
{
	rotate_a_to_index(ctx, 0);
	pb(ctx);
	rra(ctx);
	rra(ctx);
	sa(ctx);
	pa(ctx);
}

void	case_03142(t_ctx *ctx, t_element *top)
{
	if (top->index == 0 || top->index == 3 || top->index == 2)
	{
		rotate_a_to_index(ctx, 0);
		pb(ctx);
		pb(ctx);
		sa(ctx);
		pa(ctx);
		ra(ctx);
		ra(ctx);
		pa(ctx);
	}
	else
	{
		rotate_a_to_index(ctx, 1);
		pb(ctx);
		ra(ctx);
		pb(ctx);
		ra(ctx);
		pa(ctx);
		pa(ctx);
		rra(ctx);
	}
}

void	case_03241(t_ctx *ctx)
{
	rotate_a_to_index(ctx, 0);
	pb(ctx);
	sa(ctx);
	rra(ctx);
	pa(ctx);
}

void	case_02143(t_ctx *ctx)
{
	rotate_a_to_index(ctx, 1);
	pb(ctx);
	sa(ctx);
	rra(ctx);
	pa(ctx);
	rra(ctx);
}

void	case_03214(t_ctx *ctx, t_element *top)
{
	if (top->index == 0)
	{
		sa(ctx);
		rra(ctx);
		sa(ctx);
		rra(ctx);
		rra(ctx);
		sa(ctx);
		rra(ctx);
	}
	else if (top->index == 4)
	{
		pb(ctx);
		pb(ctx);
		sa(ctx);
		rra(ctx);
		pa(ctx);
		pa(ctx);
		ra(ctx);
	}
	else
	{
		rotate_a_to_index(ctx, 2);
		pb(ctx);
		pb(ctx);
		rrr(ctx);
		pa(ctx);
		pa(ctx);
		rra(ctx);
	}
}
