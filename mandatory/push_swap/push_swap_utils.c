/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:45:40 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 03:59:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*up_rotate(t_element *element)
{
	return (element->next);
}

t_element	*down_rotate(t_element *element)
{
	return (element->prev);
}

t_rotate_func	reverse_rotate(t_rotate_func rotate)
{
	if (rotate == up_rotate)
		return (down_rotate);
	else
		return (up_rotate);
}

void	rotate_order(t_ctx *ctx, \
			size_t rotate_cost, t_rotate_order_func rotate_order)
{
	while (rotate_cost > 0)
	{
		rotate_order(ctx);
		rotate_cost--;
	}
}

size_t	calc_rotate_cost(t_element **stack, \
			size_t target_index, t_rotate_func rotate)
{
	size_t		rotate_cost;
	t_element	*target;

	rotate_cost = 0;
	target = *stack;
	while (target->index != target_index)
	{
		target = rotate(target);
		rotate_cost++;
	}
	return (rotate_cost);
}
