/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasing_subsequence.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:55:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:17:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reset_tails(size_t *tails, size_t len);
static size_t	calc_lis_length(t_ctx *ctx, \
					size_t *tails, t_element **prev, t_element *element);
static size_t	lower_bound(size_t *array, size_t size, size_t value);
static void		restore_lis(t_ctx *ctx, \
					size_t *lis, size_t *tails, t_element **prev);

// パットナム法（O(n log n)）
size_t	*get_lis(t_ctx *ctx)
{
	size_t		*lis;
	size_t		*tails;
	t_element	**prev;
	size_t		length;
	size_t		i;

	lis = (size_t *)malloc(sizeof(size_t) * ctx->size);
	tails = (size_t *)malloc(sizeof(size_t) * ctx->size);
	prev = (t_element **)malloc(sizeof(t_element *) * ctx->size);
	if (lis == NULL || tails == NULL || prev == NULL)
	{
		free(lis);
		free(tails);
		free(prev);
		exit(1); // error
	}
	reset_tails(tails, ctx->size);
	ctx->lis_length = 0;
	i = 0;
	while (i < ctx->size)
	{
		length = calc_lis_length(\
			ctx, tails, prev, ctx->elements_by_index[i]);
		if (length > ctx->lis_length)
		{
			ctx->lis_length = length;
			restore_lis(ctx, lis, tails, prev);
		}
		reset_tails(tails, length);
		i++;
		if (i < ctx->size && ctx->size - i + 1 < ctx->lis_length)
			break ;
	}
	free(tails);
	free(prev);
	return (lis);
}

static void	reset_tails(size_t *tails, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		tails[i] = LIS_INIT;
		i++;
	}
}

static size_t	calc_lis_length(t_ctx *ctx, \
					size_t *tails, t_element **prev, t_element *element)
{
	size_t	length;
	size_t	position;
	size_t	i;

	length = 0;
	i = 0;
	while (i < ctx->size)
	{
		position = lower_bound(tails, length, element->index);
		if (position == length)
			length = position + 1;
		tails[position] = element->index;
		if (position > 0)
			prev[element->index] = ctx->elements_by_index[tails[position - 1]];
		else
			prev[element->index] = NULL;
		i++;
		element = element->next;
		if (ctx->lis_length >= length \
				&& ctx->lis_length - length >= ctx->size - i)
			return (0);
	}
	return (length);
}

static size_t	lower_bound(size_t *array, size_t size, size_t value)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = size;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

static void	restore_lis(t_ctx *ctx, \
				size_t *lis, size_t *tails, t_element **prev)
{
	t_element	*element;
	size_t		i;

	element = ctx->elements_by_index[tails[ctx->lis_length - 1]];
	i = ctx->lis_length;
	while (i-- > 0)
	{
		lis[i] = element->index;
		element = prev[element->index];
	}
}
