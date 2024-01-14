/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:06:03 by naadam            #+#    #+#             */
/*   Updated: 2024/01/14 07:42:53 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	send_to_b_by_midpoint(stack_a, stack_b);
	send_to_a(stack_a, stack_b);
	if (check_sorted(stack_a) == 1)
		sort_remaining(stack_a);
}

void	 sort_tatu(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (head->value == ft_min(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (ft_lstlast(head)->value == ft_max(stack_a))
		sa(stack_a);
	else if (ft_max(stack_a) == head->value
		&& ft_lstlast(head)->value != ft_min(stack_a))
		ra(stack_a);
	else if (ft_lstlast(head)->value == ft_min(stack_a)
		&& head->value != ft_max(stack_a))
		rra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_remaining(t_list **stack_a)
{
	int		smallest;
	int		small_pos;
	t_list	*temp;

	temp = *stack_a;
	assign(stack_a);
	smallest = ft_min(stack_a);
	while (temp)
	{
		if (temp->value == smallest)
			small_pos = temp->pos;
		temp = temp->next;
	}
	if (small_pos > whole(*stack_a))
	{
		while (small_pos++ < ft_lstsize(*stack_a))
			rra(stack_a);
	}
	else if (small_pos < whole(*stack_a))
	{
		while (small_pos--)
			ra(stack_a);
	}
}
