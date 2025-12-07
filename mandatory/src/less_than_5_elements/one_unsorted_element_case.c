/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_unsorted_element_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:54:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:19:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_target	get_unsorted_element(t_ctx *ctx);
void			order_swap_based_on_distance(\
						t_ctx *ctx, t_element *element, int64_t target_rank);
bool			should_swap(t_element *element, int64_t target_rank, \
						int64_t distance, t_rotate_func rotate);

void	one_unsorted_element_case(t_ctx *ctx)
{
	t_push_target	unsorted;
	int64_t			target_rank;

	unsorted = get_unsorted_element(ctx);
	target_rank = get_insert_position_rank(ctx, unsorted.element->rank);
	if (unsorted.rotate_a == down_rotate && unsorted.rotation_cost_a == 2)
	{
		if (should_swap(unsorted.element, target_rank, 2, down_rotate) == true)
		{
			execute_orders(ctx, \
				(t_order_func []){ra, ra, sa, rra, sa, NULL});
			rotate_a_to_rank(ctx, 0);
			return ;
		}
	}
	if (unsorted.rotate_a == up_rotate)
		execute_rotate_orders(ctx, unsorted.rotation_cost_a, ra);
	else
		execute_rotate_orders(ctx, unsorted.rotation_cost_a, rra);
	order_swap_based_on_distance(ctx, unsorted.element, target_rank);
	rotate_a_to_rank(ctx, 0);
}

t_push_target	get_unsorted_element(t_ctx *ctx)
{
	t_push_target	unsorted;
	int64_t			up_rotation_cost;
	int64_t			down_rotation_cost;

	ft_bzero(&unsorted, sizeof(t_push_target));
	unsorted.element = ctx->stack_a.top;
	while (!(unsorted.element->state & UNSORTED))
		unsorted.element = unsorted.element->next;
	up_rotation_cost = calc_rotation_cost(ctx->stack_a.top, \
							unsorted.element->rank, up_rotate);
	down_rotation_cost = calc_rotation_cost(ctx->stack_a.top, \
							unsorted.element->rank, down_rotate);
	if (up_rotation_cost <= down_rotation_cost)
	{
		unsorted.rotation_cost_a = up_rotation_cost;
		unsorted.rotate_a = up_rotate;
	}
	else
	{
		unsorted.rotation_cost_a = down_rotation_cost;
		unsorted.rotate_a = down_rotate;
	}
	return (unsorted);
}

void	order_swap_based_on_distance(\
			t_ctx *ctx, t_element *element, int64_t target_rank)
{
	if (should_swap(element, target_rank, 2, up_rotate) == true)
		sa(ctx);
	else if (should_swap(element, target_rank, 1, down_rotate) == true)
	{
		execute_orders(ctx, \
			(t_order_func []){rra, sa, NULL});
	}
	else if (should_swap(element, target_rank, 3, up_rotate) == true)
	{
		execute_orders(ctx, \
			(t_order_func []){sa, ra, sa, NULL});
	}
	else if (should_swap(element, target_rank, 2, down_rotate) == true)
	{
		execute_orders(ctx, \
			(t_order_func []){rra, sa, rra, sa, NULL});
	}
}

bool	should_swap(t_element *element, int64_t target_rank, \
			int64_t distance, t_rotate_func rotate)
{
	int64_t	current_distance;

	current_distance = 0;
	while (true)
	{
		element = rotate(element);
		current_distance++;
		if (element->rank != target_rank)
			continue ;
		if (current_distance == distance)
			return (true);
		else
			return (false);
	}
}
