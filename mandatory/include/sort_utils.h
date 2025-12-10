/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:07:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:19:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "types.h"

int				calc_chunk_count(int64_t unsorted_count);
void			mark_chunk_number(t_ctx *ctx);
t_element		*up_rotate(t_element *element);
t_element		*down_rotate(t_element *element);
t_rotate_func	reverse_rotate(t_rotate_func rotate);
void			rotate_a_to_rank(t_ctx *ctx, int64_t target_rank);
int64_t			calc_rotation_cost(\
	t_element *top, int64_t target_rank, t_rotate_func rotate);
int64_t			calc_push_cost(t_order *order, t_order *prev_order);

#endif