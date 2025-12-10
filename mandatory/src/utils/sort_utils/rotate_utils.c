/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:45:40 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:09:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*up_rotate(t_element *element)
{
	return (element->next);
}

t_element	*down_rotate(t_element *element)
{
	return (element->prev);
}

t_rotate_func	reverse_rotate(t_rotate_func rotate)
{
	if (rotate == up_rotate)
		return (down_rotate);
	else
		return (up_rotate);
}
