/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_rotate_with_swap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:30:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:16:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_rotate_with_swap(t_ctx *ctx)
{
	t_order *prev_order;
	t_order	*current_order;

	current_order = *(ctx->current_order);
	prev_order = current_order->prev;
	if (prev->pa == true && prev->ra > 0)
	{
		prev->pa = false;
		prev->ra--;
		prev->sa = true;
		add_order(ctx, "pa");
		add_order(ctx, "ra");
	}
}
