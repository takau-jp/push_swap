/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iddfs_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:04:59 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:58:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	iddfs(t_ctx *ctx, t_order_func order_table[ORDER_TYPES], \
				int depth_limit, int depth);

void	iddfs_sort(t_ctx *ctx)
{
	t_order_func	order_table[ORDER_TYPES];
	int				depth_limit;

	set_order_table(order_table);
	add_new_order_node(ctx);
	depth_limit = 0;
	while (true)
	{
		if (iddfs(ctx, order_table, depth_limit, 0) == true)
			return ;
		depth_limit++;
	}
}

bool	iddfs(t_ctx *ctx, t_order_func order_table[ORDER_TYPES], \
				int depth_limit, int depth)
{
	t_order_type	order_type;

	if (is_sorted(ctx) == true)
		return (true);
	if (depth == depth_limit)
		return (false);
	order_type = 0;
	while (order_type < ORDER_TYPES)
	{
		if (is_valid_order(ctx, order_type) == true)
		{
			order_table[order_type](ctx);
			if (iddfs(ctx, order_table, depth_limit, depth + 1) == true)
				return (true);
			restore_order(ctx, order_type);
		}
		order_type++;
	}
	return (false);
}
