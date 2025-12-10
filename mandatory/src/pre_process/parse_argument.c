/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:20:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:07:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_arguments(char *argv[]);
static int	*convert_to_num_array(char **inputs, int64_t size);

int	*parse_argument(char *argv[], t_ctx *ctx)
{
	char	**inputs;
	int		*num_array;

	if (!has_digit(argv))
		error();
	inputs = split_arguments(argv);
	if (inputs == NULL)
		error();
	while (inputs[ctx->size])
	{
		if (!is_int(inputs[ctx->size]))
		{
			free_splitted(inputs);
			error();
		}
		ctx->size++;
	}
	num_array = convert_to_num_array(inputs, ctx->size);
	free_splitted(inputs);
	if (num_array == NULL || !check_duplicated_num(num_array, ctx->size))
	{
		free(num_array);
		error();
	}
	return (num_array);
}

static char	**split_arguments(char *argv[])
{
	char	**splitted;
	size_t	total_len;
	int		i;
	char	*buf;

	total_len = 0;
	i = 1;
	while (argv[i])
		total_len += ft_strlen(argv[i++]) + 1;
	buf = malloc(total_len + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	i = 1;
	while (argv[i])
	{
		ft_strlcat(buf, argv[i], total_len + 1);
		if (argv[i + 1])
			ft_strlcat(buf, " ", total_len + 1);
		i++;
	}
	splitted = ft_split(buf, ' ');
	free(buf);
	return (splitted);
}

static int	*convert_to_num_array(char **inputs, int64_t size)
{
	int		*num_array;
	int64_t	i;

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
