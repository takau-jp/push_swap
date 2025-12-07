/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:25:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 12:32:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}
