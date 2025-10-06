/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_cost_target.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:28:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/02 01:15:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_costs_a(t_ctx *ctx);
void	renew_max_pushed_element_index(t_ctx *ctx);
void	search_min_cost_target_rotate(t_ctx *ctx, t_target_element *target, \
			ssize_t *min_cost, t_rotate_func rotate);

t_target_element	search_min_cost_target(t_ctx *ctx)
{
	t_target_element	target;
	ssize_t				min_cost;

	set_rotate_costs_a(ctx);
	renew_max_pushed_element_index(ctx);
	min_cost = SSIZE_MAX;
	search_min_cost_target_rotate(ctx, &target, &min_cost, down_rotate);
	search_min_cost_target_rotate(ctx, &target, &min_cost, up_rotate);
	return (target);
}

void	set_rotate_costs_a(t_ctx *ctx)
{
	t_element	*element;
	ssize_t		ra_cost;

	(*(ctx->stack_a))->ra_rotate_cost = 0;
	(*(ctx->stack_a))->rra_rotate_cost = 0;
	element = (*(ctx->stack_a))->next;
	ra_cost = 1;
	while (ra_cost < (ssize_t)ctx->size_a)
	{
		element->ra_rotate_cost = ra_cost;
		element->rra_rotate_cost = ctx->size_a - ra_cost;
		element = element->next;
		ra_cost++;
	}
}

void	renew_max_pushed_element_index(t_ctx *ctx)
{
	size_t	i;

	i = ctx->max_pushed_element_index;
	while (true)
	{
		if (ctx->elements_by_index[i]->is_pushed == true)
		{
			ctx->max_pushed_element_index = i;
			return ;
		}
		i--;
	}
}

void	search_min_cost_target_rotate(t_ctx *ctx, \
			t_target_element *target, ssize_t *min_cost, t_rotate_func rotate)
{
	t_element		*element;
	ssize_t			cost;
	t_rotate_cost	rotate_cost;

	element = *ctx->stack_b;
	rotate_cost.b = 0;
	while (element->is_pushed == false)
	{
		element = rotate(element);
		rotate_cost.b++;
	}
	while (element->is_pushed == true && rotate_cost.b <= *min_cost)
	{
		cost = calc_cost(ctx, element, &rotate_cost, rotate);
		if (cost < *min_cost \
			|| (cost == *min_cost && target->element->index < element->index))
		{
			target->element = element;
			if (rotate == up_rotate)
				target->is_up_rotate_b = true;
			else
				target->is_up_rotate_b = false;
			target->rotate_cost_b = rotate_cost.b;
			if (rotate_cost.a_reverse == 0)
			{
				target->rotate_cost_a = rotate_cost.a_same;
				target->is_up_rotate_a = target->is_up_rotate_b;
			}
			else
			{
				target->rotate_cost_a = rotate_cost.a_reverse;
				if (target->is_up_rotate_b == true)
					target->is_up_rotate_a = false;
				else
					target->is_up_rotate_a = true;
			}
			*min_cost = cost;
		}
		element = rotate(element);
		rotate_cost.b++;
		if (element == *(ctx->stack_b))
			break ;
	}
}
