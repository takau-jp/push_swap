/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_chunk_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:53:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:08:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk_count(int64_t unsorted_count)
{
	int	chunk_count;

	chunk_count \
		= (int)ft_round(ft_sqrt((double)unsorted_count) / CHUNK_COUNT_FACTOR);
	if (chunk_count == 0)
		chunk_count = 1;
	return (chunk_count);
}
