/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_longest_increasing_subsequence.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:55:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:07:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t	calc_lis_len(t_ctx *ctx, t_lis lis, t_element *element);
static int64_t	lower_bound(int64_t *array, int64_t size, int64_t value);
static void		restore_lis(t_lis lis);

t_lis	get_lis(t_ctx *ctx)
{
	t_lis	lis;
	int64_t	len;
	int64_t	i;

	init_lis_info(ctx, &lis);
	i = 0;
	while (i < ctx->size)
	{
		len = calc_lis_len(\
			ctx, lis, ctx->rank[i]);
		if (len > lis.len)
		{
			lis.len = len;
			restore_lis(lis);
		}
		reset_tails(lis, len);
		i++;
		if (i < ctx->size && ctx->size - i + 1 < lis.len)
			break ;
	}
	free(lis.tails);
	free(lis.prev);
	return (lis);
}

static int64_t	calc_lis_len(t_ctx *ctx, \
					t_lis lis, t_element *element)
{
	int64_t	len;
	int64_t	position;
	int64_t	i;

	len = 0;
	i = 0;
	while (i < ctx->size)
	{
		position = lower_bound(lis.tails, len, element->rank);
		if (position == len)
			len = position + 1;
		lis.tails[position] = element->rank;
		if (position > 0)
			lis.prev[element->rank] = lis.tails[position - 1];
		else
			lis.prev[element->rank] = LIS_INIT;
		i++;
		element = element->next;
		if (lis.len >= len \
				&& lis.len - len >= ctx->size - i)
			return (0);
	}
	return (len);
}

static int64_t	lower_bound(int64_t *array, int64_t size, int64_t value)
{
	int64_t	left;
	int64_t	right;
	int64_t	mid;

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

static void	restore_lis(t_lis lis)
{
	int64_t	i;
	int64_t	rank;

	i = lis.len;
	rank = lis.tails[lis.len - 1];
	while (i-- > 0)
	{
		lis.seq[i] = rank;
		rank = lis.prev[rank];
	}
}
