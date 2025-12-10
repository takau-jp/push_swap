/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:39:44 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 03:20:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_INSERTION_H
# define CHUNK_INSERTION_H

# include "types.h"

struct s_search_area
{
	int		random_search_count;
	double	min_rotate_b;
	double	max_rotate_b;
	double	min_big_element;
	double	max_big_element;
};

struct s_bias_factor
{
	double	rotate_b;
	double	big_element;
};

struct s_restore
{
	int64_t		cost;
	t_order		*confirmed_order_node;
	t_element	*max_unsorted_element;
};

struct s_best_state
{
	int64_t			cost;
	t_bias_factor	bias;
};

struct s_push_target
{
	double			score;
	t_element		*element;
	int64_t			rotation_cost_a;
	int64_t			rotation_cost_a_same;
	int64_t			rotation_cost_a_reverse;
	t_rotate_func	rotate_a;
	int64_t			rotation_cost_b;
	t_rotate_func	rotate_b;
};

void			chunk_insertion(t_ctx *ctx);
t_element		*get_max_unsorted_element(t_ctx *ctx);
t_element		*renew_max_unsorted_element(t_ctx *ctx);
int				mark_push_target_for_insertion(t_ctx *ctx, int chunk_number);
void			insert_chunk(t_ctx *ctx);
void			set_insert_positions(t_ctx *ctx);
void			renew_insert_positions(t_ctx *ctx, int64_t inserted_rank);
t_push_target	search_min_score_target(t_ctx *ctx);
void			calc_score(t_ctx *ctx, t_push_target *target);
void			execute_orders_rotate(t_ctx *ctx, \
					int64_t rotation_cost, t_order_func rotate_order);
void			search_best_biases(t_ctx *ctx);
void			calc_search_area(t_ctx *ctx);
void			simulate_insert_chunk(t_ctx *ctx);
void			restore(t_ctx *ctx);
void			set_random_seed(t_ctx *ctx);
double			range_random(t_ctx *ctx, double min, double max);

#endif
