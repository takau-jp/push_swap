/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:05:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/12 22:17:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ctx *ctx);

int	main(int argc, char **argv)
{
	t_ctx		ctx;
	int			*num_array;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ft_bzero(&ctx, sizeof(t_ctx));
	num_array = parse_argument(argv, &ctx);
	create_stacks(&ctx, num_array);
	if (ctx.size <= 6)
	{
		free(num_array);
		iddfs_sort(&ctx);
	}
	else
	{
		coordinate_compression(&ctx, num_array);
		free(num_array);
		mark_unsorted(&ctx);
		chunk_sort(&ctx);
	}
	print_orders(&ctx);
	clear_context(&ctx);
	return (0);
}

void	chunk_sort(t_ctx *ctx)
{
	add_new_order_node(ctx);
	if (ctx->unsorted_count > 0)
	{
		ctx->chunk_count = calc_chunk_count(ctx->unsorted_count);
		mark_chunk_number(ctx);
		chunk_division(ctx);
		chunk_insertion(ctx);
	}
	rotate_a_to_rank(ctx, 0);
}
