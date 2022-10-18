/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_of_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:47:52 by momo              #+#    #+#             */
/*   Updated: 2022/10/11 14:36:05 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_of_five(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	int		i;

	i = get_bigger_index(*stack_a);
	first_push_to_b_five(stack_a, stack_b, var);
	sort_three_value(stack_a, var);
	while (count_of_node(stack_b) != 0)
	{
		target_pos(stack_a, stack_b);
		get_cost(stack_b, var);
		find_cheapest_move(stack_a, stack_b, var);
	}
	while (check_sorted(*stack_a) != 0)
	{
		if ((*stack_a)->index > 3)
			do_ra(stack_a, var, 0);
		else if ((*stack_a)->index <= 2)
			do_rra(stack_a, var, 0);
		else if ((*stack_a)->index == 3)
			do_rra(stack_a, var, 0);
	}
}

void	first_push_to_b_five(t_stack **stack_a, t_stack **stack_b, t_var *var)
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
			if ((*stack_a)->index <= i)
				do_pb(stack_a, stack_b, var);
			else
				do_ra(stack_a, var, 0);
			j--;
		}
		var->count_node_a = count_of_node(stack_a);
	}
}
