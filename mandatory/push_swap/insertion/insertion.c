/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:47:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/02 01:51:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_initial_info(t_ctx *ctx);
ssize_t	calc_rra_cost_to_max_insert_position(t_ctx *ctx);

void	chunk_insertion(t_ctx *ctx)
{
	set_initial_info(ctx);
	search_best_biases(ctx, pushed_count);
	insert_chunk(ctx, pushed_count);
	// if (ctx->is_last_chunk == true)
		// printf("%.2lf,%.2lf\n", ctx->big_element_bias_factor, ctx->rotate_b_bias_factor);
	// printf("%zd\n", ctx->min_chunk_insertion_cost);
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
