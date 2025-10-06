/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:47:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 15:04:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		mark_pushed_for_insertion(t_ctx *ctx, int chunk_number);
void	set_initial_info(t_ctx *ctx);
ssize_t	calc_rra_cost_to_max_insert_position(t_ctx *ctx);

void	chunk_insertion(t_ctx *ctx)
{
	int		chunk_number;
	int		pushed_count;

	ctx->is_last_chunk = false;
	chunk_number = ctx->chunk_count - 1;
	while (chunk_number >= 0)
	{
		if (chunk_number == 0)
			ctx->is_last_chunk = true;
		pushed_count = mark_pushed_for_insertion(ctx, chunk_number);
		set_initial_info(ctx);
		search_best_biases(ctx, pushed_count);
		insert_chunk(ctx, pushed_count);
		// if (ctx->is_last_chunk == true)
			// printf("%.2lf,%.2lf\n", ctx->big_element_bias_factor, ctx->rotate_b_bias_factor);
		// printf("%zd\n", ctx->min_chunk_insertion_cost);
		chunk_number--;
	}
}

int	mark_pushed_for_insertion(t_ctx *ctx, int chunk_number)
{
	int			pushed_count;
	t_element	*element;
	size_t		i;

	pushed_count = 0;
	element = *(ctx->stack_b);
	i = 0;
	while (i < ctx->size_b)
	{
		if (element->chunk_number == chunk_number)
		{
			element->is_pushed = true;
			pushed_count++;
		}
		element = element->next;
		i++;
	}
	return (pushed_count);
}

void	set_initial_info(t_ctx *ctx)
{
	ctx->min_chunk_insertion_cost = SIZE_MAX;
	get_min_chunk_element_index(ctx);
	ctx->chunk_insertion_cost = 0;
	get_max_pushed_element_index(ctx);
	ctx->rra_cost_to_max_insert_position = calc_rra_cost_to_max_insert_position(ctx);
	set_insert_positions(ctx);
}

ssize_t	calc_rra_cost_to_max_insert_position(t_ctx *ctx)
{
	ssize_t		rra_cost;
	t_element	*element;
	size_t		max_insert_position_index;

	max_insert_position_index = get_insert_position_index(ctx, ctx->max_pushed_element_index);
	rra_cost = 0;
	element = *(ctx->stack_a);
	while (true)
	{
		if (element->index == max_insert_position_index)
			return (rra_cost);
		rra_cost++;
		element = element->prev;
	}
}
