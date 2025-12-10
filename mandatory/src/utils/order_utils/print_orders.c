/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:19:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:08:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_order(t_order *order);
void	merge_rotate_on_sa(t_order *order);
void	merge_rotate_on_sb(t_order *order);
void	replace_rotate_with_swap(t_order *order);

void	print_orders(t_ctx *ctx)
{
	t_order	*order;

	order = ctx->head_order;
	print_order(order);
	order = order->next;
	while (order != ctx->head_order)
	{
		merge_rotate_on_sa(order);
		merge_rotate_on_sb(order);
		replace_rotate_with_swap(order);
		print_order(order);
		order = order->next;
	}
}

void	print_order(t_order *order)
{
	while (order->ra-- > 0)
		ft_printf("ra\n");
	while (order->rra-- > 0)
		ft_printf("rra\n");
	while (order->rb-- > 0)
		ft_printf("rb\n");
	while (order->rrb-- > 0)
		ft_printf("rrb\n");
	while (order->rr-- > 0)
		ft_printf("rr\n");
	while (order->rrr-- > 0)
		ft_printf("rrr\n");
	if (order->sa == true)
		ft_printf("sa\n");
	else if (order->sb == true)
		ft_printf("sb\n");
	else if (order->ss == true)
		ft_printf("ss\n");
	if (order->pa == true)
		ft_printf("pa\n");
	else if (order->pb == true)
		ft_printf("pb\n");
}

void	merge_rotate_on_sa(t_order *order)
{
	t_order	*next_order;

	next_order = order->next;
	if (order->sa == true)
	{
		while (order->rb > 0 && next_order->ra > 0)
		{
			order->rb--;
			next_order->ra--;
			order->rr++;
		}
		while (order->rrb > 0 && next_order->rra > 0)
		{
			order->rrb--;
			next_order->rra--;
			order->rrr++;
		}
	}
}

void	merge_rotate_on_sb(t_order *order)
{
	t_order	*next_order;

	next_order = order->next;
	if (order->sb == true)
	{
		while (order->ra > 0 && next_order->rb > 0)
		{
			order->ra--;
			next_order->rb--;
			order->rr++;
		}
		while (order->rra > 0 && next_order->rrb > 0)
		{
			order->rra--;
			next_order->rrb--;
			order->rrr++;
		}
	}
}

void	replace_rotate_with_swap(t_order *order)
{
	t_order	*next_order;

	next_order = order->next;
	if (order->pa == true && order->rb > 0)
	{
		if (next_order->rrb > 0)
		{
			order->rb--;
			next_order->rrb--;
			order->sb = true;
		}
	}
	else if (order->pb == true && order->ra > 0)
	{
		if (next_order->rra > 0)
		{
			order->ra--;
			next_order->rra--;
			order->sa = true;
		}
	}
}
