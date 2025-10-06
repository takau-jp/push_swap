/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:14:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/06 01:56:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"

# define LIS_INIT SIZE_MAX
# define CHUNK_DIVISION_FACTOR 3.0

# define BIG_ELEMENT_BIAS_FACTOR 0.8
# define ROTATE_BIAS_FACTOR 1.83

typedef struct s_element {
	int		value;
	size_t	index;
	struct s_element	*next;
	struct s_element	*prev;
	bool	is_unsorted;
	int		chunk_number;
	int		index_in_chunk;
	size_t	insert_position;
	ssize_t	ra_rotate_cost;
	ssize_t	rra_rotate_cost;
}	t_element;

typedef struct s_chunk {
	bool	is_end;
	int		big_number;
	int		small_number;
	size_t	pushed_count_in_big;
	size_t	pushed_count_in_small;
	size_t	big_chunk_size;
	size_t	small_chunk_size;
}	t_chunk;

typedef	struct s_target_element {
	t_element	*element;
	size_t		rotate_cost_a;
	bool		is_up_rotate_a;
	size_t		rotate_cost_b;
	bool		is_up_rotate_b;
}	t_target_element;

typedef	struct s_rotate_cost {
	ssize_t	b;
	ssize_t	a_same;
	ssize_t	a_reverse;
}	t_rotate_cost;

typedef struct s_efficient_rotate {
	size_t		rotate_cost;
	t_element	*pivot_element;
	bool		is_up_rotation_start;
	bool		is_end_big_chunk;
	bool		is_end_small_chunk;
	int			pushed_count;
	size_t		unpushed_count;
	size_t		reverse_rotate_cost;
}	t_efficient_rotate;

typedef struct s_order {
	ssize_t	ra;
	ssize_t	rra;
	ssize_t	rb;
	ssize_t	rrb;
	ssize_t	rr;
	ssize_t	rrr;
	bool	pa;
	bool	pb;
	bool	sa;
	bool	sb;
	bool	ss;
	struct s_order *prev;
	struct s_order *next;
}	t_order;

typedef struct s_restore {
	size_t		size_b;
	size_t		max_pushed_element_index;
}	t_restore;

typedef struct s_ctx {
	t_element	**stack_a;
	t_element	**stack_b;
	t_order		**head_order;
	t_order		**current_order;
	t_element	**elements_by_index;
	size_t		size;
	size_t		size_a;
	size_t		size_b;
	size_t		unsorted_count;
	size_t		lis_length;
	int			chunk_count;
	bool		is_last_chunk;
	double		slope;
	double		min_intercept;
	double		max_intercept;
	double		rotate_b_bias_factor;
	double		big_element_bias_factor;
	double		best_rotate_b_bias_factor;
	double		best_rotate_a_bias_factor;
	double		best_big_element_bias_factor;
	size_t		min_chunk_insertion_cost;
	t_order		**save_order_node;
	double		best_score;
	size_t		max_pushed_element_index;
	size_t		insertion_cost;
	t_restore	restore;
}	t_ctx;

typedef t_element	*(*t_rotate_func)(t_element *);
typedef void	(*t_rotate_order_func)(t_ctx *);

// pre_process
int					*parse_argument(int argc, char **argv, t_ctx *ctx);
void				parse_argument_error(char **inputs, int *num_array);
void				free_splitted(char **splitted);
t_element			*create_stack_a(t_ctx *ctx, int *num_array);
bool				sort_num_array(int *num_array, size_t array_size);
void				coordinate_compression(t_ctx *ctx, int *sorted);
void				create_element_array_by_index(t_ctx *ctx);
size_t				*get_lis(t_ctx *ctx);
void				init_status(t_ctx *ctx, t_element **stack_a);
void				mark_unsorted(t_ctx *ctx, size_t *lis);
// list_utils
void				ps_lstclear(t_element **lst);
void				ps_lstadd_back(t_element **lst, t_element *new);
void				ps_lstadd_front(t_element **lst, t_element *new);
t_element			*ps_lstnew(int value);
// orders
void				ra(t_ctx *ctx);
void				rb(t_ctx *ctx);
void				rr(t_ctx *ctx);
void				rra(t_ctx *ctx);
void				rrb(t_ctx *ctx);
void				rrr(t_ctx *ctx);
void				pa(t_ctx *ctx);
void				pb(t_ctx *ctx);
void				sa(t_ctx *ctx);
void				sb(t_ctx *ctx);
void				ss(t_ctx *ctx);
void				add_order(t_ctx *ctx, char *order);
void				add_new_order_node(t_ctx *ctx);
void				add_ra(t_order *order_node);
void				add_rb(t_order *order_node);
void				add_rr(t_order *order_node);
void				add_rra(t_order *order_node);
void				add_rrb(t_order *order_node);
void				add_rrr(t_order *order_node);
void				add_pa(t_ctx *ctx);
void				add_pb(t_ctx *ctx);
void				add_sa(t_ctx *ctx);
void				add_sb(t_ctx *ctx);
void				add_ss(t_ctx *ctx);
void				restore_pa(t_ctx *ctx);
void				restore_sb(t_element **stack_b);
void				restore_rotate_order(t_ctx *ctx, t_order *order_node);
void				print_orders(t_ctx *ctx);
void				clear_orders(t_order **lst);
// push_swap
void				push_swap(t_ctx *ctx);
t_element			*up_rotate(t_element *element);
t_element			*down_rotate(t_element *element);
t_rotate_func 		reverse_rotate(t_rotate_func rotate);
void				rotate_order(t_ctx *ctx, size_t rotate_cost, t_rotate_order_func rotate_order);
size_t				calc_rotate_cost(t_element **stack, \
						size_t target_index, t_rotate_func rotate);
void				chunk_division(t_ctx *ctx);
void				mark_pushed_for_division_big_chunk(t_ctx *ctx, t_chunk *chunk);
void				mark_pushed_for_division_small_chunk(t_ctx *ctx, t_chunk *chunk);
void				push_chunk(t_ctx *ctx, t_chunk *chunk, t_efficient_rotate rotation, t_rotate_func rotate);
void				order_push(t_ctx *ctx, t_chunk *chunk, \
						t_target_element target, t_rotate_func rotate);
t_efficient_rotate	efficient_rotate(t_ctx *ctx, t_chunk *chunk);
size_t				calc_distance_to_next_pushed(t_element *element, t_rotate_func rotate);

void				chunk_insertion(t_ctx *ctx);
void				baseline_model(t_ctx *ctx, int pushed_count);
void				search_best_biases(t_ctx *ctx, int pushed_count);
void				calc_grid_search_area(t_ctx *ctx, int pushed_count);
void				first_grid_search_rotate_b(t_ctx *ctx, int pushed_count);
void				second_grid_search_rotate_b(t_ctx *ctx, int pushed_count);
void				third_grid_search_rotate_b(t_ctx *ctx, int pushed_count);

void				first_grid_search_rotate_b_last_chunk(t_ctx *ctx, int pushed_count);
void				second_grid_search_rotate_b_last_chunk(t_ctx *ctx, int pushed_count);
void				third_grid_search_rotate_b_last_chunk(t_ctx *ctx, int pushed_count);

void				grid_search_big_element(t_ctx *ctx, int pushed_count);
void				grid_search_rotate_a(t_ctx *ctx, int pushed_count);

void				simulate_insert_chunk(t_ctx *ctx, int pushed_count);
void				evaluate_bias_factors(t_ctx *ctx, double rotate_b_bias_factor, \
						double big_element_bias_factor, double rotate_a_bias_factor);
void				restore_stacks(t_ctx *ctx);
void				set_restore_info(t_ctx *ctx);
void				restore_info(t_ctx *ctx);

void				insert_chunk(t_ctx *ctx, int pushed_count);
void				set_insert_positions(t_ctx *ctx);
void				renew_insert_positions(t_ctx *ctx, size_t inserted_index);
size_t				calc_insertion_cost(t_order *order);
ssize_t				calc_rra_cost_to_min_chunk_element(t_ctx *ctx);
t_target_element	search_min_cost_target(t_ctx *ctx);
ssize_t				calc_cost(t_ctx *ctx, t_element *element, t_rotate_cost *rotate_cost, t_rotate_func rotate);
ssize_t				calc_cost_last_chunk(t_ctx *ctx, t_element *element, t_rotate_cost *rotate_cost, t_rotate_func rotate);

size_t				get_insert_position_index(t_ctx *ctx, size_t insert_index);
void				get_max_pushed_element_index(t_ctx *ctx);
void				get_min_chunk_element_index(t_ctx *ctx);
void				order_insert(t_ctx *ctx, t_target_element target);
void				rotate_a_to_index(t_ctx *ctx, size_t target_index);
void				one_unsorted_element_case(t_ctx *ctx);
void				two_unsorted_elements_case(t_ctx *ctx);
void				case_0321(t_ctx *ctx);
void				case_04312(t_ctx *ctx);
void				case_04213(t_ctx *ctx, t_element *top);
void				case_04231(t_ctx *ctx, t_element *top);
void				case_04132(t_ctx *ctx, t_element *top);
void				case_01432(t_ctx *ctx, t_element *top);
void				case_02413(t_ctx *ctx, t_element *top);
void				case_02431(t_ctx *ctx, t_element *top);
void				case_03421(t_ctx *ctx);
void				case_03142(t_ctx *ctx, t_element *top);
void				case_03241(t_ctx *ctx);
void				case_02143(t_ctx *ctx);
void				case_03214(t_ctx *ctx, t_element *top);
void				three_unsorted_elements_case(t_ctx *ctx);

// TEST
// void print_stack(t_element **stack, size_t size);

// void	push_chunk_bad_case(t_ctx *ctx, t_chunk *chunk, \
// 			t_efficient_rotate efficient_rotate, t_rotate_func rotate);


// void	calc_bias_factors(t_ctx *ctx);
// double	spearmans_rank_correlation_coefficient(t_ctx *ctx);
// bool	change_big_element_bias_factor(t_ctx *ctx);
// bool	change_rotate_bias_factor(t_ctx *ctx);


// void	calc_bias_factors(t_ctx *ctx, double head_ndcg);
// double	calc_local_normalized_documented_cumulative_gain(t_ctx *ctx);
// double	calc_head_normalized_documented_cumulative_gain(t_ctx *ctx);
// double	calc_normalized_documented_cumulative_gain_last_chunk(t_ctx *ctx);

#endif