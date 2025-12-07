/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:18:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/03 23:18:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_orders(t_ctx *ctx)
{
	t_order	*current;
	t_order	*next;

	if (ctx->head_order == NULL)
		return ;
	current = ctx->head_order->next;
	while (current != ctx->head_order)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(ctx->head_order);
	ctx->head_order = NULL;
}
