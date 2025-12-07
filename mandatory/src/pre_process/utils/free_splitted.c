/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:19:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 18:57:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted(char **splitted)
{
	int64_t	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
