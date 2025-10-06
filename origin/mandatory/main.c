/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:05:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/28 16:14:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_order(t_order *order);

void	count_orders(t_ctx *ctx)
{
	t_order	*order;
	int		count;

	count = 0;
	order = *(ctx->head_order);
	count += count_order(order);
	order = order->next;
	while (order != *(ctx->head_order))
	{
		count += count_order(order);
		order = order->next;
	}
	printf("%d\n", count);
}

int	count_order(t_order *order)
{
	int count = 0;
	while (order->ra-- > 0)
		count++;
	while (order->rra-- > 0)
		count++;
	while (order->rb-- > 0)
		count++;
	while (order->rrb-- > 0)
		count++;
	while (order->rr-- > 0)
		count++;
	while (order->rrr-- > 0)
		count++;
	if (order->pa == true)
		count++;
	else if (order->pb == true)
		count++;
	else if (order->sa == true)
		count++;
	else if (order->sb == true)
		count++;
	else if (order->ss == true)
		count++;
	return (count);
}

int	main(int argc, char **argv)
{
	t_ctx		ctx;
	int			*num_array;
	t_element	*stack_a;
	size_t		*lis;
	t_element	*stack_b;
	t_order		*head_order;
	t_order		*current_order;
	t_order		*save_order_node;

	ft_bzero(&ctx, sizeof(t_ctx));
	num_array = parse_argument(argc, argv, &ctx);
	stack_a = create_stack_a(&ctx, num_array);
	if (!sort_num_array(num_array, ctx.size))
	{
		free(num_array);
		ps_lstclear(&stack_a);
		ft_dprintf(STDERR_FILENO, "Error\n");
		exit(1);
	}
	stack_b = NULL;
	ctx.stack_a = &stack_a;
	ctx.size_a = ctx.size;
	ctx.stack_b = &stack_b;
	coordinate_compression(&ctx, num_array);
	free(num_array);
	create_element_array_by_index(&ctx);
	lis = get_lis(&ctx);
	ctx.unsorted_count = ctx.size - ctx.lis_length;
	mark_unsorted(&ctx, lis);
	free(lis);
	head_order = NULL;
	ctx.head_order = &head_order;
	ctx.current_order = &current_order;
	ctx.save_order_node = &save_order_node;
	add_new_order_node(&ctx);
	push_swap(&ctx);
	print_orders(&ctx);
	// count_orders(&ctx);
	free(ctx.elements_by_index);
	ps_lstclear(ctx.stack_a);
	clear_orders(ctx.head_order);
	return (0);
}
