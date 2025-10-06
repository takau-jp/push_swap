/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:41:07 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_sort(int *array, int *buf, size_t left, size_t right);

bool	sort_num_array(int *num_array, size_t array_size)
{
	int	*buf;

	buf = (int *)malloc(sizeof(int) * array_size);
	if (buf == NULL)
	{
		free(buf);
		return (false);
	}
	merge_sort(num_array, buf, 0, array_size - 1);
	free(buf);
	return (true);
}

static void	merge_sort(int *array, int *buf, size_t left, size_t right)
{
	size_t	mid;
	size_t	i;
	size_t	j;
	size_t	k;

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
