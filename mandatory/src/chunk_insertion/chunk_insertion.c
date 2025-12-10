/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:47:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:06:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_insertion(t_ctx *ctx)
{
	int	chunk_number;

	chunk_number = ctx->chunk_count - 1;
	set_random_seed(ctx);
	while (ctx->stack_b.size)
	{
		ctx->cost = 0;
		ctx->max_unsorted_element = get_max_unsorted_element(ctx);
		ctx->chunk_size = mark_push_target_for_insertion(ctx, chunk_number);
		ctx->best_state.cost = INT64_MAX;
		search_best_biases(ctx);
		insert_chunk(ctx);
		chunk_number--;
	}
}
