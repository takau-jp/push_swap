/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_new_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:11:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 12:16:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_element	*ps_stack_new(int value)
{
	t_element	*new;

	new = (t_element *)ft_calloc(sizeof(t_element), 1);
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}
