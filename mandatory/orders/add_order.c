/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/05 22:19:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rotate_order(t_ctx *ctx, char *order);
bool	prev_swap_check(t_ctx *ctx, char *order);

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
	t_order *order_node;

	order_node = *(ctx->current_order);
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

bool	prev_swap_check(t_ctx *ctx, char *order)
{
	t_order *prev_node;

	prev_node = (*(ctx->current_order))->prev;
	if (ctx->current_order != ctx->head_order)
	{
		if (!ft_strcmp("ra", order) && prev_node->sb == true \
				&& (prev_node->ra < prev_node->rb || prev_node->rra > 0))
			return (true);
		else if (!ft_strcmp("rb", order) && prev_node->sa == true \
				&& (prev_node->rb < prev_node->ra || prev_node->rrb > 0))
			return (true);
		else if (!ft_strcmp("rra", order) && prev_node->sb == true \
				&& (prev_node->rra < prev_node->rrb || prev_node->ra > 0))
			return (true);
		else if (!ft_strcmp("rrb", order) && prev_node->sa == true \
				&& (prev_node->rrb < prev_node->rra || prev_node->rb > 0))
			return (true);
	}
	return (false);
}

void	add_new_order_node(t_ctx *ctx)
{
	t_order	*new;
	t_order	*head;
	t_order	*last;

	new = (t_order *)ft_calloc(sizeof(t_order), 1);
	if (!new)
	{
		exit(1); //error
	}
	if (*(ctx->head_order) == NULL)
	{
		*(ctx->head_order) = new;
		*(ctx->current_order) = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	head = *(ctx->head_order);
	last = *(ctx->current_order);
	new->prev = last;
	new->next = head;
	last->next = new;
	head->prev = new;
	*(ctx->current_order) = new;
}
