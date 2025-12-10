/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:41:07 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:47:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_sort(int *array, int *buf, int64_t left, int64_t right);

void	sort_num_array(t_ctx *ctx, int *num_array)
{
	const int64_t	array_size = ctx->size;
	int				*buf;

	buf = (int *)malloc(sizeof(int) * array_size);
	if (buf == NULL)
	{
		free(num_array);
		clear_context(ctx);
		error();
	}
	merge_sort(num_array, buf, 0, array_size - 1);
	free(buf);
}

static void	merge_sort(int *array, int *buf, int64_t left, int64_t right)
{
	int64_t	mid;
	int64_t	i;
	int64_t	j;
	int64_t	k;

	if (left == right)
		return ;
	mid = left + (right - left) / 2;
	merge_sort(array, buf, left, mid);
	merge_sort(array, buf, mid + 1, right);
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
	{
		if (array[i] < array[j])
			buf[k++] = array[i++];
		else
			buf[k++] = array[j++];
	}
	while (i <= mid)
		buf[k++] = array[i++];
	while (j <= right)
		buf[k++] = array[j++];
	ft_memcpy(&array[left], buf, sizeof(int) * (right - left + 1));
}
