/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validations_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:45:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 19:03:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	has_digit(char *argv[])
{
	int		i;
	int		j;
	bool	found_digit;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		found_digit = false;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				found_digit = true;
			else if (argv[i][j] != ' ' \
				&& argv[i][j] != '+' && argv[i][j] != '-')
				return (false);
			j++;
		}
		if (found_digit == false)
			return (false);
		i++;
	}
	return (true);
}

bool	is_int(char *input)
{
	int		sign;
	long	num;

	sign = 1;
	if (*input == '+' || *input == '-')
	{
		if (*(input++) == '-')
			sign = -1;
	}
	if (*input == '\0')
		return (false);
	num = 0;
	while (*input != '\0')
	{
		if (!ft_isdigit(*input))
			return (false);
		num = num * 10 + (*input - '0');
		if (sign == 1 && num > INT_MAX)
			return (false);
		else if (sign == -1 && num > (long)INT_MAX + 1)
			return (false);
		input++;
	}
	return (true);
}

bool	check_duplicated_num(int *num_array, int64_t size)
{
	int64_t	i;
	int64_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num_array[i] == num_array[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
