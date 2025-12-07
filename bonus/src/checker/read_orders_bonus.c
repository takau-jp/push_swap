/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_orders_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:16:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 14:47:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	select_order(t_ctx *ctx, char *order);

void	read_orders(t_ctx *ctx)
{
	char	*order;

	order = get_next_line(0);
	while (order != NULL)
	{
		if (!ft_strcmp(order, ""))
		{
			free(order);
			break ;
		}
		if (select_order(ctx, order) == false)
		{
			free(order);
			ps_stack_clear(ctx);
			error();
		}
		free(order);
		order = get_next_line(0);
	}
}

bool	select_order(t_ctx *ctx, char *order)
{
	if (!ft_strcmp(order, "pa\n"))
		pa(ctx);
	else if (!ft_strcmp(order, "pb\n"))
		pb(ctx);
	else if (!ft_strcmp(order, "sa\n"))
		sa(ctx);
	else if (!ft_strcmp(order, "sb\n"))
		sb(ctx);
	else if (!ft_strcmp(order, "ss\n"))
		ss(ctx);
	else if (!ft_strcmp(order, "ra\n"))
		ra(ctx);
	else if (!ft_strcmp(order, "rra\n"))
		rra(ctx);
	else if (!ft_strcmp(order, "rb\n"))
		rb(ctx);
	else if (!ft_strcmp(order, "rrb\n"))
		rrb(ctx);
	else if (!ft_strcmp(order, "rr\n"))
		rr(ctx);
	else if (!ft_strcmp(order, "rrr\n"))
		rrr(ctx);
	else
		return (false);
	return (true);
}
