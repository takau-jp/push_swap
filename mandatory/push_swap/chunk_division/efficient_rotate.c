/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:34:07 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 02:15:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_efficient_rotate	calc_efficient_rotate(t_ctx *ctx, t_chunk *chunk, \
						t_rotate_func rotate);
t_efficient_rotate	init_efficient_rotate(t_ctx *ctx, t_chunk *chunk, \
						t_rotate_func rotate);
bool				is_pivot(t_element *element, t_efficient_rotate	efficient_rotate, \
						t_rotate_func rotate);
t_element			*reverse_rotate_pivot(t_ctx *ctx, t_element *pivot, \
						t_efficient_rotate *efficient_rotate, t_rotate_func *rotate);

t_efficient_rotate	efficient_rotate(t_ctx *ctx, t_chunk *chunk)
{
	t_efficient_rotate	up_rotation_start;
	t_efficient_rotate	down_rotation_start;

	up_rotation_start = calc_efficient_rotate(ctx, chunk, up_rotate);
	down_rotation_start = calc_efficient_rotate(ctx, chunk, down_rotate);
	if (up_rotation_start.rotate_cost < down_rotation_start.rotate_cost)
	{
		up_rotation_start.is_up_rotation_start = true;
		return (up_rotation_start);
	}
	else
	{
		down_rotation_start.is_up_rotation_start = false;
		return (down_rotation_start);
	}
}

t_efficient_rotate	calc_efficient_rotate(t_ctx *ctx, t_chunk *chunk, t_rotate_func rotate)
{
	t_efficient_rotate	efficient_rotate;
	t_element			*element;

	efficient_rotate = init_efficient_rotate(ctx, chunk, rotate);
	element = *(ctx->stack_a);
	while (true)
	{
		if (element->is_pushed == true)
		{
			efficient_rotate.pushed_count--;
			if (efficient_rotate.pushed_count == 0)
				return (efficient_rotate);
			if (efficient_rotate.pivot_element == NULL && is_pivot(element, efficient_rotate, rotate))
			{
				element = reverse_rotate_pivot(ctx, element, &efficient_rotate, &rotate);
				continue ;
			}
			if (rotate == down_rotate)
				efficient_rotate.rotate_cost++;
		}
		else
			efficient_rotate.unpushed_count++;
		element = rotate(element);
		efficient_rotate.rotate_cost++;
	}
}

t_efficient_rotate	init_efficient_rotate(t_ctx *ctx, t_chunk *chunk, t_rotate_func rotate)
{
	t_efficient_rotate	efficient_rotate;

	efficient_rotate.rotate_cost = 0;
	efficient_rotate.pivot_element = NULL;
	efficient_rotate.is_end_big_chunk = false;
	if (chunk->small_number != ctx->chunk_count - 1)
		efficient_rotate.is_end_small_chunk = false;
	else
		efficient_rotate.is_end_small_chunk = true;
	efficient_rotate.reverse_rotate_cost = calc_distance_to_next_pushed(*(ctx->stack_a), reverse_rotate(rotate));
	if (chunk->big_number == chunk->small_number)
		efficient_rotate.pushed_count = chunk->pushed_count_in_big;
	else
		efficient_rotate.pushed_count = chunk->pushed_count_in_big + chunk->pushed_count_in_small;
	efficient_rotate.unpushed_count = 0;
	return (efficient_rotate);
}

bool	is_pivot(t_element *element, t_efficient_rotate	efficient_rotate, t_rotate_func rotate)
{
	size_t	current_rotate_cost;
	size_t	reverse_rotate_cost;

	current_rotate_cost = calc_distance_to_next_pushed(element, rotate);
	if (rotate == down_rotate)
		current_rotate_cost += efficient_rotate.pushed_count;
	reverse_rotate_cost = efficient_rotate.reverse_rotate_cost + efficient_rotate.unpushed_count;
	if (rotate == up_rotate)
		reverse_rotate_cost += efficient_rotate.pushed_count;
	if (current_rotate_cost < reverse_rotate_cost)
		return (false);
	else
		return (true);
}

t_element	*reverse_rotate_pivot(t_ctx *ctx, t_element *pivot, t_efficient_rotate *efficient_rotate, t_rotate_func *rotate)
{
	efficient_rotate->pivot_element = pivot;
	efficient_rotate->rotate_cost += efficient_rotate->unpushed_count;
	if (*rotate == up_rotate)
		efficient_rotate->rotate_cost++;
	*rotate = reverse_rotate(*rotate);
	return ((*rotate)(*(ctx->stack_a)));
}
