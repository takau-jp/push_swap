/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:14:44 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/12 22:08:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

typedef struct s_ctx		t_ctx;
typedef struct s_stack		t_stack;
typedef struct s_element	t_element;

struct s_stack
{
	t_element	*top;
	int64_t		size;	
};

struct s_ctx
{
	int64_t		size;
	t_stack		stack_a;
	t_stack		stack_b;
};

struct s_element
{
	int			value;
	t_element	*next;
	t_element	*prev;
};

int			*parse_argument(char *argv[], t_ctx *ctx);
bool		has_digit(char *argv[]);
bool		is_int(char *input);
bool		check_duplicated_num(int *num_array, int64_t size);
void		free_splitted(char **splitted);
void		create_stacks(t_ctx *ctx, int *num_array);
t_element	*ps_stack_new(int value);
void		ps_stack_add_front(t_element **stack, t_element *new);
void		ps_stack_add_back(t_element **stack, t_element *new);
void		ps_stack_clear(t_ctx *ctx);
void		read_orders(t_ctx *ctx);
void		pa(t_ctx *ctx);
void		pb(t_ctx *ctx);
void		sa(t_ctx *ctx);
void		sb(t_ctx *ctx);
void		ss(t_ctx *ctx);
void		ra(t_ctx *ctx);
void		rra(t_ctx *ctx);
void		rb(t_ctx *ctx);
void		rrb(t_ctx *ctx);
void		rr(t_ctx *ctx);
void		rrr(t_ctx *ctx);
bool		is_sorted(t_ctx *ctx);
void		error(void);

#endif