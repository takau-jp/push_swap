/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:51:21 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 22:49:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_UTILS_H
# define ORDER_UTILS_H

# include "types.h"

struct s_order
{
	int64_t	ra;
	int64_t	rra;
	int64_t	rb;
	int64_t	rrb;
	int64_t	rr;
	int64_t	rrr;
	bool	pa;
	bool	pb;
	bool	sa;
	bool	sb;
	bool	ss;
	t_order	*prev;
	t_order	*next;
};

void	pa(t_ctx *ctx);
void	pb(t_ctx *ctx);
void	ra(t_ctx *ctx);
void	rb(t_ctx *ctx);
void	rr(t_ctx *ctx);
void	rra(t_ctx *ctx);
void	rrb(t_ctx *ctx);
void	rrr(t_ctx *ctx);
void	sa(t_ctx *ctx);
void	sb(t_ctx *ctx);
void	ss(t_ctx *ctx);
void	add_order(t_ctx *ctx, char *order);
void	add_new_order_node(t_ctx *ctx);
void	add_pa(t_ctx *ctx);
void	add_pb(t_ctx *ctx);
void	add_ra(t_order *order_node);
void	add_rb(t_order *order_node);
void	add_rr(t_order *order_node);
void	add_rra(t_order *order_node);
void	add_rrb(t_order *order_node);
void	add_rrr(t_order *order_node);
void	add_sa(t_ctx *ctx);
void	add_sb(t_ctx *ctx);
void	add_ss(t_ctx *ctx);
void	restore_pa(t_ctx *ctx);
void	restore_pb(t_ctx *ctx);
void	restore_rotate_order(t_ctx *ctx, t_order *order_node);
void	print_orders(t_ctx *ctx);
void	clear_orders(t_ctx *ctx);

#endif