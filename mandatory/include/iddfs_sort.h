/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iddfs_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:32:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:56:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDDFS_SORT_H
# define IDDFS_SORT_H

# include "types.h"

# define ORDER_TYPES 11

enum e_order_type
{
	RA,
	RRA,
	RB,
	RRB,
	RR,
	RRR,
	SA,
	SB,
	SS,
	PA,
	PB,
};

void	iddfs_sort(t_ctx *ctx);
void	set_order_table(t_order_func order_table[ORDER_TYPES]);
bool	is_sorted(t_ctx *ctx);
bool	is_valid_order(t_ctx *ctx, t_order_type order_type);
void	restore_order(t_ctx *ctx, t_order_type order_type);

#endif