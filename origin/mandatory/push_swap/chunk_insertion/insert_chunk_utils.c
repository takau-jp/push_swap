/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_chunk_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:41:49 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 14:42:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_insert_positions(t_ctx *ctx)
{
	size_t	i;
	size_t	insert_position;

	insert_position = get_insert_position_index(ctx, ctx->max_pushed_element_index);
	i = insert_position;
	while (true)
	{
		if (i == 0)
			i = ctx->size - 1;
		else
			i--;
		if (ctx->elements_by_index[i]->is_unsorted == false)
			insert_position = i;
		else if (ctx->elements_by_index[i]->is_pushed == true)
			ctx->elements_by_index[i]->insert_position = insert_position;
		if (i == ctx->min_chunk_element_index)
			return ;
	}
}

void	renew_insert_positions(t_ctx *ctx, size_t inserted_index)
{
	size_t	i;

	if (inserted_index == 0)
		return ;
	i = inserted_index - 1;
	while (true)
	{
		if (ctx->elements_by_index[i]->is_pushed == false)
			return ;
		ctx->elements_by_index[i]->insert_position = inserted_index;
		if (i == 0)
			return ;
		i--;
	}
}

size_t	calc_insertion_cost(t_order *order)
{
	size_t	insertion_cost;

	insertion_cost = 0;
	insertion_cost += order->ra;
	insertion_cost += order->rra;
	insertion_cost += order->rb;
	insertion_cost += order->rrb;
	insertion_cost += order->rr;
	insertion_cost += order->rrr;
	insertion_cost += 1;
	return (insertion_cost);
}

ssize_t	calc_rra_cost_to_min_chunk_element(t_ctx *ctx)
{
	ssize_t		rra_cost;
	t_element	*element;

	rra_cost = 0;
	element = *(ctx->stack_a);
	while (true)
	{
		if (element->index == ctx->min_chunk_element_index)
			return (rra_cost);
		rra_cost++;
		element = element->prev;
	}
}
