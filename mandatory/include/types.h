/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:21:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:40:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// struct
typedef struct s_ctx				t_ctx;
typedef struct s_stack				t_stack;
typedef struct s_element			t_element;
typedef struct s_order				t_order;
typedef struct s_lis				t_lis;
typedef struct s_chunk				t_chunk;
typedef struct s_cost_data			t_cost_data;
typedef struct s_efficient_rotation	t_efficient_rotation;
typedef struct s_push_target		t_push_target;
typedef struct s_search_area		t_search_area;
typedef struct s_bias_factor		t_bias_factor;
typedef struct s_best_state			t_best_state;
typedef struct s_restore			t_restore;

// enum
typedef enum e_order_type			t_order_type;

// function
typedef t_element					*(*t_rotate_func)(t_element *);
typedef void						(*t_order_func)(t_ctx *);

#endif