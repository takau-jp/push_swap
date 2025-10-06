/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:19:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:31:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_order(t_order *order);

void	print_orders(t_ctx *ctx)
{
	t_order	*order;

	order = *(ctx->head_order);
	print_order(order);
	order = order->next;
	while (order != *(ctx->head_order))
	{
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
	if (order->pa == true)
		ft_printf("pa\n");
	else if (order->pb == true)
		ft_printf("pb\n");
	else if (order->sa == true)
		ft_printf("sa\n");
	else if (order->sb == true)
		ft_printf("sb\n");
	else if (order->ss == true)
		ft_printf("ss\n");
}
