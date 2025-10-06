/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotate_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:51:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:18:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calc_distance_to_next_pushed(
			t_element *element, t_rotate_func rotate)
{
	size_t	distance;

	distance = 0;
	if (element->is_pushed == false)
		distance++;
	element = rotate(element);
	while (element->is_pushed == false)
	{
		distance++;
		element = rotate(element);
	}
	return (distance);
}
