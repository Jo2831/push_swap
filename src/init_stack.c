/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:28:05 by ytapano           #+#    #+#             */
/*   Updated: 2024/01/15 01:28:06 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack_a, t_list **stack_b, char **arguments)
{
	int		i;
	int		value;
	t_list	*new;

	i = 0;
	while (arguments[i] != 0)
	{
		value = ft_atoi(arguments[i], stack_a, stack_b, arguments);
		new = ft_lstnew(value);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	if (check_dup(stack_a) == false)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		free_tda(arguments);
		ft_error();
	}
	index_stack(stack_a);
}
