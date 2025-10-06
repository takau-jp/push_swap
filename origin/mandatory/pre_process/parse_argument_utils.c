/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:43:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:32:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_argument_error(char **inputs, int *num_array)
{
	if (inputs != NULL)
		free_splitted(inputs);
	free(num_array);
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(1);
}

void	free_splitted(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
