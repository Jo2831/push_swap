/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:28:11 by ytapano           #+#    #+#             */
/*   Updated: 2024/01/15 01:28:12 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse(stack_a) == -1)
		return (-1);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse(stack_b) == -1)
		return (-1);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
	return (0);
}
