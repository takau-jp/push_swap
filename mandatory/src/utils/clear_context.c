/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_context.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:50:00 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:51:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_context(t_ctx *ctx)
{
	free(ctx->rank);
	free(ctx->unsorted_rank);
	ps_stack_clear(ctx);
	clear_orders(ctx);
}
