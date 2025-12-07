/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:19:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 19:03:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_splitted(char **splitted)
{
	int64_t	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
