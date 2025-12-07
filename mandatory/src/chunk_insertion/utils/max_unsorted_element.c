/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_unsorted_element_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:03:13 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:57:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*get_max_unsorted_element(t_ctx *ctx)
{
	int64_t	i;

	i = ctx->size - 1;
	while (true)
	{
		if (ctx->rank[i]->state & UNSORTED)
		{
			return (ctx->rank[i]);
		}
		if (i == 0)
			return (NULL);
		i--;
	}
}

t_element	*renew_max_unsorted_element(t_ctx *ctx)
{
	int64_t	i;

	i = ctx->max_unsorted_element->rank;
	while (true)
	{
		if (ctx->rank[i]->state & UNSORTED)
		{
			return (ctx->rank[i]);
		}
		if (i == 0)
			return (NULL);
		i--;
	}
}
