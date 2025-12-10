/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:30:47 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:48:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_best_rotate(t_push_target *target);
double	biased_rotation_cost(t_ctx *ctx, t_push_target *target);
double	biased_element_cost(t_ctx *ctx, t_element *element);

void	calc_score(t_ctx *ctx, t_push_target *target)
{
	if (target->rotate_b == up_rotate)
	{
		target->rotation_cost_a_same \
			= ctx->rank[target->element->insert_position]->up.cost;
		target->rotation_cost_a_reverse \
			= ctx->rank[target->element->insert_position]->down.cost;
	}
	else
	{
		target->rotation_cost_a_same \
			= ctx->rank[target->element->insert_position]->down.cost;
		target->rotation_cost_a_reverse \
			= ctx->rank[target->element->insert_position]->up.cost;
	}
	target->score = calc_best_rotate(target);
	target->score += biased_rotation_cost(ctx, target);
	target->score += biased_element_cost(ctx, target->element);
}

double	calc_best_rotate(t_push_target *target)
{
	if (target->rotation_cost_b < target->rotation_cost_a_same)
	{
		if (target->rotation_cost_a_same \
			< target->rotation_cost_a_reverse + target->rotation_cost_b)
		{
			target->rotation_cost_a = target->rotation_cost_a_same;
			target->rotate_a = target->rotate_b;
			return (target->rotation_cost_a);
		}
		else
		{
			target->rotation_cost_a = target->rotation_cost_a_reverse;
			target->rotate_a = reverse_rotate(target->rotate_b);
			return (target->rotation_cost_b + target->rotation_cost_a);
		}
	}
	target->rotation_cost_a = target->rotation_cost_a_same;
	target->rotate_a = target->rotate_b;
	return (target->rotation_cost_b);
}

double	biased_rotation_cost(t_ctx *ctx, t_push_target *target)
{
	double	biased_cost;

	if (target->rotate_b == up_rotate \
		|| ctx->stack_b.size <= ctx->chunk_size)
		biased_cost = target->rotation_cost_b * ctx->bias.rotate_b;
	else
		biased_cost = 0;
	if (target->rotate_a == up_rotate)
		biased_cost += 0;
	else
		biased_cost += target->rotation_cost_a;
	return (biased_cost);
}

double	biased_element_cost(t_ctx *ctx, t_element *element)
{
	return ((ctx->max_unsorted_element->rank - element->rank) \
										* ctx->bias.big_element);
}
