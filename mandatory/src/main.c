/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:05:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 10:41:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ctx *ctx);

int	main(int argc, char **argv)
{
	t_ctx		ctx;
	int			*num_array;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ft_bzero(&ctx, sizeof(t_ctx));
	num_array = parse_argument(argv, &ctx);
	create_stacks(&ctx, num_array);
	coordinate_compression(&ctx, num_array);
	free(num_array);
	create_rank_array(&ctx);
	mark_unsorted(&ctx);
	add_new_order_node(&ctx);
	sort(&ctx);
	print_orders(&ctx);
	free(ctx.rank);
	free(ctx.unsorted_rank);
	ps_stack_clear(&ctx);
	clear_orders(&ctx);
	return (0);
}

void	sort(t_ctx *ctx)
{
	if (ctx->unsorted_count > 0)
	{
		if (ctx->size == 3)
			sa(ctx);
		else if (ctx->size <= 5 && ctx->unsorted_count == 1)
			one_unsorted_element_case(ctx);
		else if (ctx->size <= 5 && ctx->unsorted_count == 2)
			two_unsorted_elements_case(ctx);
		else if (ctx->size == 5 && ctx->unsorted_count == 3)
			three_unsorted_elements_case(ctx);
		else
		{
			ctx->chunk_count = calc_chunk_count(ctx->unsorted_count);
			mark_chunk_number(ctx);
			chunk_division(ctx);
			chunk_insertion(ctx);
		}
	}
	rotate_a_to_rank(ctx, 0);
}
