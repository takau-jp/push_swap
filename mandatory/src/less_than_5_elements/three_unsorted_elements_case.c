/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_unsorted_elements_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:56:19 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 09:18:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_unsorted_elements_case(t_ctx *ctx)
{
	execute_orders(ctx, \
			(t_order_func []){pb, pb, sa, rrr, pa, pa, NULL});
	rotate_a_to_rank(ctx, 0);
}
