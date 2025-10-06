/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:49:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	binary_search_index(
					int *sorted, int value, size_t left, size_t right);

void	coordinate_compression(t_ctx *ctx, int *sorted)
{
	t_element	*element;
	size_t		i;

	i = 0;
	element = *(ctx->stack_a);
	while (i < ctx->size)
	{
		element->index = binary_search_index(
				sorted, element->value, 0, ctx->size - 1);
		i++;
		element = element->next;
	}
}

static size_t	binary_search_index(
					int *sorted, int value, size_t left, size_t right)
{
	size_t	mid;

	mid = left + (right - left) / 2;
	if (sorted[mid] == value)
		return (mid);
	if (sorted[mid] > value)
		return (binary_search_index(sorted, value, left, mid - 1));
	else
		return (binary_search_index(sorted, value, mid + 1, right));
}
