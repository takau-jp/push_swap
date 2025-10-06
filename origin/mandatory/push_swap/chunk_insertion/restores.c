/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restores.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:48:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 14:57:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_stacks(t_ctx *ctx)
{
	t_order	*restore_order_node;

	while ((*(ctx->current_order))->prev != (*(ctx->save_order_node)))
	{
		restore_order_node = (*(ctx->current_order))->prev;
		if (restore_order_node->pa == true)
		{
			restore_pa(ctx);
			(*ctx->stack_b)->is_unsorted = true;
			(*ctx->stack_b)->is_pushed = true;
			ctx->size_a--;
			ctx->size_b++;
		}
		else if (restore_order_node->sb == true)
			restore_sb(ctx->stack_b);
		restore_rotate_order(ctx, restore_order_node);
		restore_order_node->prev->next = restore_order_node->next;
		restore_order_node->next->prev = restore_order_node->prev;
		free(restore_order_node);
	}
}

void	set_restore_info(t_ctx *ctx)
{
	ctx->restore.chunk_insertion_cost = ctx->chunk_insertion_cost;
	ctx->restore.max_pushed_element_index = ctx->max_pushed_element_index;
	ctx->restore.rra_cost_to_max_insert_position = ctx->rra_cost_to_max_insert_position;
}

void	restore_info(t_ctx *ctx)
{
	ctx->chunk_insertion_cost = ctx->restore.chunk_insertion_cost;
	ctx->max_pushed_element_index = ctx->restore.max_pushed_element_index;
	ctx->rra_cost_to_max_insert_position = ctx->restore.rra_cost_to_max_insert_position;
	set_insert_positions(ctx);
}
