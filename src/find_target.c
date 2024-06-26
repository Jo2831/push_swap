/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:27:41 by ytapano           #+#    #+#             */
/*   Updated: 2024/01/15 01:27:41 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_index(t_list **stack_a, t_list *stack_b)
{
	int		min_diff;
	int		diff;
	int		target;
	t_list	*temp_a;

	temp_a = *stack_a;
	target = 0;
	min_diff = INT_MAX;
	while (temp_a)
	{
		diff = temp_a->index - stack_b->index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target);
}

t_list	*cheapest_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		cheapest_cost;
	int		cost;
	t_list	*cheapest_pos;

	temp = *stack_b;
	cheapest_cost = INT_MAX;
	while (temp)
	{
		(*stack_a)->target_pos = find_target_index(stack_a, temp);
		cost = retrieve_cost_for_target(*stack_a, (*stack_a)->target_pos);
		cost += temp->cost_b;
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest_pos = temp;
		}
		temp = temp->next;
	}
	return (cheapest_pos);
}

int	retrieve_cost_for_target(t_list *stack, int target_pos)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->pos == target_pos)
			return (temp->cost_a);
		temp = temp->next;
	}
	return (-1);
}
