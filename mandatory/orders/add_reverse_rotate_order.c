/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_reverse_rotate_order.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:58:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rra(t_order *order_node)
{
	if (order_node->ra > 0)
		order_node->ra--;
	else if (order_node->rrb > 0)
	{
		order_node->rrb--;
		order_node->rrr++;
	}
	else if (order_node->rr > 0)
	{
		order_node->rr--;
		order_node->rb++;
	}
	else
		order_node->rra++;
}

void	add_rrb(t_order *order_node)
{
	if (order_node->rb > 0)
		order_node->rb--;
	else if (order_node->rra > 0)
	{
		order_node->rra--;
		order_node->rrr++;
	}
	else if (order_node->rr > 0)
	{
		order_node->rr--;
		order_node->ra++;
	}
	else
		order_node->rrb++;
}

void	add_rrr(t_order *order_node)
{
	if (order_node->rr > 0)
		order_node->rr--;
	else if (order_node->ra > 0)
	{
		order_node->ra--;
		order_node->rrb++;
	}
	else if (order_node->rb > 0)
	{
		order_node->rb--;
		order_node->rra++;
	}
	else
		order_node->rrr++;
}