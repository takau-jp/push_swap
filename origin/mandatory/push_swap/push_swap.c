/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:55:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/21 17:17:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ctx *ctx)
{
	if (ctx->unsorted_count > 0)
	{
		if (ctx->size == 3)
			sa(ctx);
		else if (ctx->size <= 5 && ctx->unsorted_count == 1)
			one_unsorted_element_case(ctx);
		else if (ctx->size <= 5 && ctx->unsorted_count == 2)
			two_unsorted_elements_case(ctx);
		else if (ctx->size == 5 && ctx->unsorted_count == 3)
			three_unsorted_elements_case(ctx);
		else
		{
			chunk_division(ctx);
			chunk_insertion(ctx);
		}
	}
	rotate_a_to_index(ctx, 0);
}

