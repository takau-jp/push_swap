/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:20:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:33:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_inputs(char **inputs);
static bool	check_input(char *input);
static int	*convert_to_num_array(char **inputs, size_t size);
static bool	check_duplicated_num(int *num_array, size_t size);

// tabはどうするべき？　"1 2 3" 4はどうするべき？
int	*parse_argument(int argc, char **argv, t_ctx *ctx)
{
	char	**inputs;
	int		*num_array;

	if (argc == 2)
		inputs = ft_split(argv[1], ' ');
	else
		inputs = argv + 1;
	if (argc == 1 || inputs == NULL)
		parse_argument_error(NULL, NULL);
	while (inputs[ctx->size])
		ctx->size++;
	if (ctx->size == 0)
		parse_argument_error(inputs, NULL);
	if (!check_inputs(inputs))
		parse_argument_error(inputs, NULL);
	num_array = convert_to_num_array(inputs, ctx->size);
	if (num_array == NULL)
		parse_argument_error(inputs, num_array);
	if (!check_duplicated_num(num_array, ctx->size))
		parse_argument_error(inputs, num_array);
	if (argc == 2)
		free_splitted(inputs);
	return (num_array);
}

static bool	check_inputs(char **inputs)
{
	size_t	i;

	i = 1;
	while (inputs[i])
	{
		if (!check_input(inputs[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_input(char *input)
{
	int		sign;
	long	num;

	// tabは？
	while (ft_isspace(*input))
		input++;
	sign = 1;
	if (*input == '+' || *input == '-')
	{
		if (*(input++) == '-')
			sign = -1;
	}
	num = 0;
	// 先頭0はどうする？
	while (ft_isdigit(*input))
	{
		num = num * 10 + (*input - '0');
		if (sign == 1 && num > INT_MAX)
			return (false);
		else if (sign == -1 && num > (long)INT_MAX + 1)
			return (false);
		input++;
	}
	if (*input != '\0')
		return (false);
	return (true);
}

static int	*convert_to_num_array(char **inputs, size_t size)
{
	int		*num_array;
	size_t	i;

	num_array = (int *)malloc(sizeof(int) * size);
	if (num_array == NULL)
		return (NULL);
	i = 0;
	while (inputs[i])
	{
		num_array[i] = ft_atoi(inputs[i]);
		i++;
	}
	return (num_array);
}

static bool	check_duplicated_num(int *num_array, size_t size)
{
	size_t	i;
	size_t	j;

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
