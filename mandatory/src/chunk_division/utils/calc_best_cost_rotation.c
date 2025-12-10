/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_cost_rotation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:02:39 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:31:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*get_next_push_target(\
	t_element *element, t_rotate_func rotate);
bool		evaluate_rotation_cost(\
	int64_t *best_cost, t_element *goal, t_rotate_func rotate);
bool		evaluate_rotation_cost_with_pivot(int64_t *best_cost, \
	t_element *goal, t_element *pivot, t_rotate_func rotate);

void	calc_best_cost_rotation_without_pivot(\
	t_ctx *ctx, int64_t *best_cost, t_efficient_rotation *rotation)
{
	t_element	*goal;

	goal = get_next_push_target(ctx->stack_a.top, down_rotate);
	if (evaluate_rotation_cost(best_cost, goal, up_rotate) == true)
		*rotation = (t_efficient_rotation){up_rotate, NULL};
	goal = get_next_push_target(ctx->stack_a.top, up_rotate);
	if (evaluate_rotation_cost(best_cost, goal, down_rotate) == true)
		*rotation = (t_efficient_rotation){down_rotate, NULL};
}

void	calc_best_cost_rotation_with_pivot(t_ctx *ctx, int64_t *best_cost, \
	t_efficient_rotation	*rotation, t_rotate_func rotate)
{
	t_element	*pivot;
	t_element	*goal;
	t_element	*end;

	end = get_next_push_target(ctx->stack_a.top, rotate);
	pivot = ctx->stack_a.top;
	while (true)
	{
		while (!(pivot->state & PUSH_TARGET))
			pivot = rotate(pivot);
		if (pivot == end)
			return ;
		goal = get_next_push_target(pivot, rotate);
		if (evaluate_rotation_cost_with_pivot(\
				best_cost, goal, pivot, rotate) == true)
			*rotation = (t_efficient_rotation){rotate, pivot};
		pivot = rotate(pivot);
	}
}

t_element	*get_next_push_target(t_element *element, t_rotate_func rotate)
{
	element = rotate(element);
	while (!(element->state & PUSH_TARGET))
		element = rotate(element);
	return (element);
}

bool	evaluate_rotation_cost(\
	int64_t *best_cost, t_element *goal, t_rotate_func rotate)
{
	int64_t	cost;

	if (rotate == up_rotate)
	{
		cost = goal->up.cost;
	}
	else
	{
		cost = goal->down.cost;
	}
	if (cost < *best_cost)
	{
		*best_cost = cost;
		return (true);
	}
	return (false);
}

bool	evaluate_rotation_cost_with_pivot(int64_t *best_cost, \
	t_element *goal, t_element *pivot, t_rotate_func rotate)
{
	int64_t	cost;

	if (rotate == up_rotate)
	{
		cost = pivot->up.cost + (pivot->up.unpush_count + 1) \
					+ goal->down.cost;
	}
	else
	{
		cost = pivot->down.cost + pivot->down.unpush_count \
					+ goal->up.cost;
	}
	if (cost < *best_cost)
	{
		*best_cost = cost;
		return (true);
	}
	return (false);
}
