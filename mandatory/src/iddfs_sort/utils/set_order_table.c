/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:03:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:56:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_order_table(t_order_func order_table[ORDER_TYPES])
{
	order_table[RA] = ra;
	order_table[RRA] = rra;
	order_table[RB] = rb;
	order_table[RRB] = rrb;
	order_table[RR] = rr;
	order_table[RRR] = rrr;
	order_table[SA] = sa;
	order_table[SB] = sb;
	order_table[SS] = ss;
	order_table[PA] = pa;
	order_table[PB] = pb;
}
