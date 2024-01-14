/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chedup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:29:41 by ytapano           #+#    #+#             */
/*   Updated: 2024/01/15 01:29:42 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

bool	check_dup(t_list **stack_a)
{
	t_list	*temp;
	t_list	*sec;

	temp = *stack_a;
	while (temp != NULL)
	{
		sec = temp->next;
		while (sec != NULL)
		{
			if (sec->value == temp->value)
				return (false);
			sec = sec->next;
		}
		temp = temp->next;
	}
	return (true);
}
