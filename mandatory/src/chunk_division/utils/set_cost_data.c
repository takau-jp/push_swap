/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:05:36 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:05:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_data(t_ctx *ctx, t_rotate_func rotate)
{
	t_element	*element;
	t_cost_data	cost_data;

	element = ctx->stack_a.top;
	ft_bzero(&cost_data, sizeof(t_cost_data));
	while (true)
	{
		cost_data.cost++;
		if (element->state & PUSH_TARGET)
		{
			if (element->state & PUSH_TARGET && rotate == up_rotate)
				element->up = cost_data;
			else if (element->state & PUSH_TARGET && rotate == down_rotate)
				element->down = cost_data;
			if (rotate == down_rotate)
				cost_data.cost++;
		}
		else
			cost_data.unpush_count++;
		element = rotate(element);
		if (element == ctx->stack_a.top)
			break ;
	}
}
