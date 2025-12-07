/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:14:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/28 14:25:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		*num_array;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ft_bzero(&ctx, sizeof(t_ctx));
	num_array = parse_argument(argv, &ctx);
	create_stacks(&ctx, num_array);
	free(num_array);
	read_orders(&ctx);
	if (is_sorted(&ctx) == true)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ps_stack_clear(&ctx);
}
