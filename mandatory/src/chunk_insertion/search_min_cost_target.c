/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_cost_target.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:28:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 10:02:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_a_cost(t_ctx *ctx);
void	search_min_cost_target_with_rotate(\
	t_ctx *ctx, t_push_target *min_cost_target, t_rotate_func rotate);

t_push_target	search_min_cost_target(t_ctx *ctx)
{
	t_push_target	min_cost_target;

	set_rotate_a_cost(ctx);
	ctx->max_unsorted_element = renew_max_unsorted_element(ctx);
	min_cost_target.cost = ft_get_infinity();
	search_min_cost_target_with_rotate(ctx, &min_cost_target, down_rotate);
	search_min_cost_target_with_rotate(ctx, &min_cost_target, up_rotate);
	return (min_cost_target);
}

void	set_rotate_a_cost(t_ctx *ctx)
{
	t_element	*element;
	int64_t		ra_cost;

	ctx->stack_a.top->ra_cost = 0;
	ctx->stack_a.top->rra_cost = 0;
	element = ctx->stack_a.top->next;
	ra_cost = 1;
	while (ra_cost < (int64_t)ctx->stack_a.size)
	{
		element->ra_cost = ra_cost;
		element->rra_cost = ctx->stack_a.size - ra_cost;
		element = element->next;
		ra_cost++;
	}
}

void	search_min_cost_target_with_rotate(t_ctx *ctx, \
	t_push_target *min_cost_target, t_rotate_func rotate)
{
	t_push_target	target;

	target.rotate_b = rotate;
	target.element = ctx->stack_b.top;
	target.rotation_cost_b = 0;
	while (!(target.element->state & PUSH_TARGET))
	{
		target.element = rotate(target.element);
		target.rotation_cost_b++;
	}
	while ((target.element->state & PUSH_TARGET) \
			&& (double)target.rotation_cost_b <= min_cost_target->cost)
	{
		calc_cost(ctx, &target);
		if (target.cost < min_cost_target->cost \
			|| (target.cost == min_cost_target->cost \
				&& min_cost_target->element->rank < target.element->rank))
		{
			*min_cost_target = target;
		}
		target.element = rotate(target.element);
		target.rotation_cost_b++;
		if (target.element == ctx->stack_b.top)
			break ;
	}
}
