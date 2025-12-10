/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_order_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:13:15 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:07:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_ra(t_order *order_node)
{
	if (order_node->rra > 0)
		order_node->rra--;
	else if (order_node->rb > 0)
	{
		order_node->rb--;
		order_node->rr++;
	}
	else if (order_node->rrr > 0)
	{
		order_node->rrr--;
		order_node->rrb++;
	}
	else
		order_node->ra++;
}

void	add_rb(t_order *order_node)
{
	if (order_node->rrb > 0)
		order_node->rrb--;
	else if (order_node->ra > 0)
	{
		order_node->ra--;
		order_node->rr++;
	}
	else if (order_node->rrr > 0)
	{
		order_node->rrr--;
		order_node->rra++;
	}
	else
		order_node->rb++;
}

void	add_rr(t_order *order_node)
{
	if (order_node->rrr > 0)
		order_node->rrr--;
	else if (order_node->rra > 0)
	{
		order_node->rra--;
		order_node->rb++;
	}
	else if (order_node->rrb > 0)
	{
		order_node->rrb--;
		order_node->ra++;
	}
	else
		order_node->rr++;
}
