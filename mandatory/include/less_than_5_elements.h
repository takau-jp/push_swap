/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_5_elements.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:39:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/03 22:54:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_THAN_5_ELEMENTS_H
# define LESS_THAN_5_ELEMENTS_H

# include "types.h"

void	one_unsorted_element_case(t_ctx *ctx);
void	two_unsorted_elements_case(t_ctx *ctx);
void	case_0321(t_ctx *ctx);
void	two_unsorted_elements_case_04xxx(t_ctx *ctx);
void	case_04312(t_ctx *ctx);
void	case_04213(t_ctx *ctx, t_element *top);
void	case_04231(t_ctx *ctx, t_element *top);
void	case_04132(t_ctx *ctx, t_element *top);
void	two_unsorted_elements_case_0x4xx(t_ctx *ctx);
void	case_01432(t_ctx *ctx, t_element *top);
void	case_02413(t_ctx *ctx, t_element *top);
void	case_02431(t_ctx *ctx, t_element *top);
void	case_03421(t_ctx *ctx);
void	two_unsorted_elements_case_0xx4x(t_ctx *ctx);
void	case_03142(t_ctx *ctx, t_element *top);
void	case_03241(t_ctx *ctx);
void	case_02143(t_ctx *ctx);
void	case_03214(t_ctx *ctx, t_element *top);
void	three_unsorted_elements_case(t_ctx *ctx);

#endif