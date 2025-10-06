/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_unsorted_element_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:54:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/27 22:21:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_target_element	get_unsorted_element(t_ctx *ctx);
void				order_swap_based_on_distance(t_ctx *ctx, t_element *element, size_t target_index);
bool				should_swap(t_element *element, size_t target_index, \
						size_t distance, t_rotate_func rotate);

void	one_unsorted_element_case(t_ctx *ctx)
{
	t_target_element	unsorted;
	size_t				target_index;

	unsorted = get_unsorted_element(ctx);
	target_index = get_insert_position_index(ctx, unsorted.element->index);
	if (unsorted.is_up_rotate_a == false && unsorted.rotate_cost_a == 2)
	{
		if (should_swap(unsorted.element, target_index, 2, down_rotate) == true)
		{
			rotate_order(ctx, 2, ra);
			sa(ctx);
			rra(ctx);
			sa(ctx);
			rotate_a_to_index(ctx, 0);
			return;
		}
	}
	if (unsorted.is_up_rotate_a == true)
		rotate_order(ctx, unsorted.rotate_cost_a, ra);
	else
		rotate_order(ctx, unsorted.rotate_cost_a, rra);
	order_swap_based_on_distance(ctx, unsorted.element, target_index);
	rotate_a_to_index(ctx, 0);
}

t_target_element	get_unsorted_element(t_ctx *ctx)
{
	t_target_element	unsorted;
	size_t				up_rotate_cost;
	size_t				down_rotate_cost;

	ft_bzero(&unsorted, sizeof(t_target_element));
	unsorted.element = *(ctx->stack_a);
	while (unsorted.element->is_unsorted == false)
		unsorted.element = unsorted.element->next;
	up_rotate_cost = calc_rotate_cost(ctx->stack_a, unsorted.element->index, up_rotate);
	down_rotate_cost = calc_rotate_cost(ctx->stack_a, unsorted.element->index, down_rotate);
	if (up_rotate_cost <= down_rotate_cost)
	{
		unsorted.rotate_cost_a = up_rotate_cost;
		unsorted.is_up_rotate_a = true;
	}
	else
	{
		unsorted.rotate_cost_a = down_rotate_cost;
		unsorted.is_up_rotate_a = false;
	}
	return (unsorted);
}

void	order_swap_based_on_distance(t_ctx *ctx, t_element *element, size_t target_index)
{
	if (should_swap(element, target_index, 2, up_rotate) == true)
		sa(ctx);
	else if (should_swap(element, target_index, 1, down_rotate) == true)
	{
		rra(ctx);
		sa(ctx);
	}
	else if (should_swap(element, target_index, 3, up_rotate) == true)
	{
		sa(ctx);
		ra(ctx);
		sa(ctx);
	}
	else if (should_swap(element, target_index, 2, down_rotate) == true)
	{
		rra(ctx);
		sa(ctx);
		rra(ctx);
		sa(ctx);
	}
}

bool	should_swap(t_element *element, size_t target_index, \
			size_t distance, t_rotate_func rotate)
{
	size_t	current_distance;

	current_distance = 0;
	while (true)
	{
		element = rotate(element);
		current_distance++;
		if (element->index != target_index)
			continue ;
		if (current_distance == distance)
			return (true);
		else
			return (false);
	}
}
