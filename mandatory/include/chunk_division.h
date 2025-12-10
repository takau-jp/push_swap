/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_division.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:26:46 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:58:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_DIVISION_H
# define CHUNK_DIVISION_H

# include "types.h"

struct s_chunk
{
	int		number;
	int		count;
};

struct s_efficient_rotation
{
	t_rotate_func	rotate;
	t_element		*pivot;
};

void	chunk_division(t_ctx *ctx);
void	mark_push_target_for_division(t_ctx *ctx, t_chunk *chunk);
void	renew_push_target(\
	t_ctx *ctx, t_chunk *big_chunk, t_chunk *small_chunk);
void	set_cost_data(t_ctx *ctx, t_rotate_func rotate);
void	calc_best_cost_rotation_without_pivot(\
	t_ctx *ctx, int64_t *best_cost, t_efficient_rotation *rotation);
void	calc_best_cost_rotation_with_pivot(t_ctx *ctx, \
	int64_t *best_cost, t_efficient_rotation *rotation, t_rotate_func rotate);

#endif
