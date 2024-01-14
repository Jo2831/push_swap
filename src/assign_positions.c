/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:59:06 by naadam            #+#    #+#             */
/*   Updated: 2024/01/15 01:26:53 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign(t_list **stack)
{
	int		pos;
	t_list	*temp;

	pos = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = pos++;
		temp = temp->next;
	}
	return ;
}
