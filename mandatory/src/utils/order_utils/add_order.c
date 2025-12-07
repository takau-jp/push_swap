/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 04:34:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rotate_order(t_ctx *ctx, char *order);

void	add_order(t_ctx *ctx, char *order)
{
	if (*order == 'r')
		add_rotate_order(ctx, order);
	else if (!ft_strcmp("pa", order))
		add_pa(ctx);
	else if (!ft_strcmp("pb", order))
		add_pb(ctx);
	else if (!ft_strcmp("sa", order))
		add_sa(ctx);
	else if (!ft_strcmp("sb", order))
		add_sb(ctx);
	else if (!ft_strcmp("ss", order))
		add_ss(ctx);
}

void	add_rotate_order(t_ctx *ctx, char *order)
{
	t_order	*order_node;

	order_node = ctx->current_order;
	if (!ft_strcmp("rr", order))
	{
		add_rr(order_node);
		return ;
	}
	else if (!ft_strcmp("rrr", order))
	{
		add_rrr(order_node);
		return ;
	}
	if (!ft_strcmp("ra", order))
		add_ra(order_node);
	else if (!ft_strcmp("rb", order))
		add_rb(order_node);
	else if (!ft_strcmp("rra", order))
		add_rra(order_node);
	else if (!ft_strcmp("rrb", order))
		add_rrb(order_node);
}

void	add_new_order_node(t_ctx *ctx)
{
	t_order	*new;

	new = (t_order *)ft_calloc(sizeof(t_order), 1);
	if (!new)
	{
		free(ctx->rank);
		free(ctx->unsorted_rank);
		ps_stack_clear(ctx);
		clear_orders(ctx);
		error();
	}
	if (ctx->head_order == NULL)
	{
		ctx->head_order = new;
		ctx->current_order = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	new->prev = ctx->current_order;
	new->next = ctx->head_order;
	ctx->current_order->next = new;
	ctx->head_order->prev = new;
	ctx->current_order = new;
}
