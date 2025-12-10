/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:03:53 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:04:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_ctx *ctx)
{
	t_element	*element;

	if (ctx->stack_a.size != ctx->size || ctx->stack_b.size != 0)
		return (false);
	element = ctx->stack_a.top;
	while (element->next != ctx->stack_a.top)
	{
		if (element->value >= element->next->value)
			return (false);
		element = element->next;
	}
	return (true);
}
