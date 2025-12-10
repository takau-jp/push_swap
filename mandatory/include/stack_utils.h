/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:08:10 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/07 16:05:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "types.h"

t_element	*ps_stack_new(int value);
void		ps_stack_add_front(t_element **stack, t_element *new);
void		ps_stack_add_back(t_element **stack, t_element *new);
void		ps_stack_clear(t_ctx *ctx);

#endif