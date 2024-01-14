/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:54:04 by naadam            #+#    #+#             */
/*   Updated: 2023/09/26 18:54:04 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_pos;
	t_list	*target;

	while (*stack_b)
	{
		assign(stack_a);
		assign(stack_b);
		find_cost(stack_a, stack_b);
		cheapest_pos = cheapest_cost(stack_a, stack_b);
		target = retrieve_target_for_cheapest(stack_a, cheapest_pos);
		rearrange(stack_a, stack_b, cheapest_pos, target);
		pa(stack_b, stack_a);
	}
}