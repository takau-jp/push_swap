/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_score_target.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:28:52 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 02:58:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_a_cost(t_ctx *ctx);
void	search_min_score_target_with_rotate(\
	t_ctx *ctx, t_push_target *min_score_target, t_rotate_func rotate);

t_push_target	search_min_score_target(t_ctx *ctx)
{
	t_push_target	min_score_target;

	set_rotate_a_cost(ctx);
	ctx->max_unsorted_element = renew_max_unsorted_element(ctx);
	min_score_target.score = ft_get_infinity();
	search_min_score_target_with_rotate(ctx, &min_score_target, down_rotate);
	search_min_score_target_with_rotate(ctx, &min_score_target, up_rotate);
	return (min_score_target);
}

void	set_rotate_a_cost(t_ctx *ctx)
{
	t_element	*element;
	int64_t		ra_cost;

	ctx->stack_a.top->up.cost = 0;
	ctx->stack_a.top->down.cost = 0;
	element = ctx->stack_a.top->next;
	ra_cost = 1;
	while (ra_cost < ctx->stack_a.size)
	{
		element->up.cost = ra_cost;
		element->down.cost = ctx->stack_a.size - ra_cost;
		element = element->next;
		ra_cost++;
	}
}

void	search_min_score_target_with_rotate(t_ctx *ctx, \
	t_push_target *min_score_target, t_rotate_func rotate)
{
	t_push_target	target;

	target.rotate_b = rotate;
	target.element = ctx->stack_b.top;
	target.rotation_cost_b = 0;
	while (!(target.element->state & PUSH_TARGET))
	{
		target.element = rotate(target.element);
		target.rotation_cost_b++;
	}
	while ((target.element->state & PUSH_TARGET) \
			&& (double)target.rotation_cost_b <= min_score_target->score)
	{
		calc_score(ctx, &target);
		if (target.score < min_score_target->score \
			|| (target.score == min_score_target->score \
				&& min_score_target->element->rank < target.element->rank))
		{
			*min_score_target = target;
		}
		target.element = rotate(target.element);
		target.rotation_cost_b++;
		if (target.element == ctx->stack_b.top)
			break ;
	}
}
