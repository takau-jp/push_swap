/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:14:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 10:18:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"
# include "types.h"
# include "error.h"
# include "less_than_5_elements.h"
# include "order_utils.h"
# include "pre_process.h"
# include "sort_utils.h"  
# include "stack_utils.h"
# include "chunk_division.h"
# include "chunk_insertion.h"

# define LIS_INIT SIZE_MAX
# define CHUNK_COUNT_FACTOR 3.0

struct s_stack
{
	t_element	*top;
	int64_t		size;	
};

struct s_ctx
{
	int64_t				size;
	t_element			**rank;
	t_element			**unsorted_rank;
	t_stack				stack_a;
	t_stack				stack_b;
	t_order				*head_order;
	t_order				*current_order;
	int64_t				unsorted_count;
	int					chunk_count;
	int					chunk_size;
	t_restore			restore;
	t_search_area		search_area;
	t_best_state		best_state;
	t_bias_factor		bias;
	t_element			*max_unsorted_element;
	t_element			*min_chunk_element;
	uint32_t			random_seed;
};

enum e_element_state
{
	SORTED = 0,
	UNSORTED = (1 << 0),
	PUSH_TARGET = (1 << 1),
};

struct s_element
{
	int						value;
	t_element				*next;
	t_element				*prev;
	int64_t					rank;
	int64_t					unsorted_rank;
	enum e_element_state	state;
	int						chunk_number;
	t_cost_data				up;
	t_cost_data				down;
	int64_t					insert_position;
	int64_t					ra_cost;
	int64_t					rra_cost;
};

#endif