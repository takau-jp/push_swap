/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:49:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/12 22:12:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t	find_rank(
					int *sorted, int value, int64_t left, int64_t right);

void	coordinate_compression(t_ctx *ctx, int *num_array)
{
	t_element	*element;
	int64_t		i;

	sort_num_array(ctx, num_array);
	ctx->rank \
		= (t_element **)malloc(sizeof(t_element *) * ctx->size);
	if (ctx->rank == NULL)
	{
		free(num_array);
		clear_context(ctx);
		error();
	}
	i = 0;
	element = ctx->stack_a.top;
	while (i < ctx->size)
	{
		element->rank = find_rank(
				num_array, element->value, 0, ctx->size - 1);
		ctx->rank[element->rank] = element;
		i++;
		element = element->next;
	}
}

static int64_t	find_rank(
					int *sorted, int value, int64_t left, int64_t right)
{
	int64_t	mid;

	mid = left + (right - left) / 2;
	if (sorted[mid] == value)
		return (mid);
	if (sorted[mid] > value)
		return (find_rank(sorted, value, left, mid - 1));
	else
		return (find_rank(sorted, value, mid + 1, right));
}
