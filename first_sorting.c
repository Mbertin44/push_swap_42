/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:08:17 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/11 14:35:59 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	first_push_to_b(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	int	i;
	int	j;

	i = find_median(stack_a);
	j = count_of_node(stack_a);
	var->count_node_a = 0;
	while (var->count_node_a != 3)
	{
		while (j != 0)
		{
			if ((*stack_a)->index < i)
				do_pb(stack_a, stack_b, var);
			else
				do_ra(stack_a, var, 0);
			j--;
		}
		if (var->count_node_a != 3)
			do_pb(stack_a, stack_b, var);
		var->count_node_a = count_of_node(stack_a);
	}
}

void	sort_three_value(t_stack **stack_a, t_var *var)
{
	t_stack	*head;

	head = *stack_a;
	if ((*stack_a)->index == get_bigger_index(*stack_a))
	{
		do_ra(stack_a, var, 0);
		if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a, 0);
	}
	else if ((*stack_a)->next->index == get_bigger_index(*stack_a))
	{
		do_rra(stack_a, var, 0);
		if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a, 0);
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a, 0);
}
