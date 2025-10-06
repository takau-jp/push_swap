/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_unsorted_elements_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:56:19 by stanaka2          #+#    #+#             */
/*   Updated: 2025/09/03 01:19:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 04321 case

// // 04321 [7]
// pb pb 321
// sa 231
// rrr 123
// pa pa 40123
// ra 01234

// // 43210 [8]
// pb pb 210
// sa 120
// rrr 012
// pa pa 34012
// ra ra 01234

// // 32104 [8]
// pb pb 104
// sa 014
// rrr 401
// pa pa 23401
// rra rra 01234

// // 21043 [7]
// pb pb 043
// sa 403
// rrr 340
// pa pa 12340
// rra 01234

// // 10432 [6]
// pb pb 432
// sa 342
// rrr 234
// pa pa 01234

void	three_unsorted_elements_case(t_ctx *ctx)
{
	pb(ctx);
	pb(ctx);
	sa(ctx);
	rrr(ctx);
	pa(ctx);
	pa(ctx);
	rotate_a_to_index(ctx, 0);
}

