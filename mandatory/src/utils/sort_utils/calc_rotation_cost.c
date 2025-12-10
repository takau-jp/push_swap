/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotation_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:26:14 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:08:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	calc_rotation_cost(\
			t_element *element, int64_t target_rank, t_rotate_func rotate)
{
	int64_t		rotation_cost;

	rotation_cost = 0;
	while (element->rank != target_rank)
	{
		element = rotate(element);
		rotation_cost++;
	}
	return (rotation_cost);
}
