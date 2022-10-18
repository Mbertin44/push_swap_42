/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_cheapest_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:51:37 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/11 14:34:06 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	get_cost(t_stack **stack_b, t_var *var)
{
	t_stack	*head_b;

	head_b = *stack_b;
	while (*stack_b)
	{
		(*stack_b)->cost_b = (*stack_b)->pos;
		if ((*stack_b)->pos > var->count_node_b / 2)
			(*stack_b)->cost_b = (var->count_node_b - (*stack_b)->pos) * -1;
		(*stack_b)->cost_a = (*stack_b)->target_pos;
		if ((*stack_b)->target_pos > var->count_node_a / 2)
			(*stack_b)->cost_a = (var->count_node_a
					- (*stack_b)->target_pos) * -1;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
}

int	abs_value(int cost)
{
	int	value;

	value = cost;
	if (cost < 0)
		value = cost * -1;
	return (value);
}

void	find_cheapest_move(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	t_stack	*head;
	t_stack	*cheapest_node;
	int		cost;

	cost = INT_MAX;
	head = *stack_b;
	while (head)
	{
		if (abs_value(head->cost_a) + abs_value(head->cost_b) < cost)
		{
			cost = abs_value(head->cost_a) + abs_value(head->cost_b);
			cheapest_node = head;
		}
		head = head->next;
	}
	sorting(stack_a, stack_b, cheapest_node, var);
}
