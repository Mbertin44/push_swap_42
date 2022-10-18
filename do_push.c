/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:18:09 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/27 10:14:58 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	do_pb(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	t_stack	*first_node_a;

	if (*stack_a)
	{
		first_node_a = *stack_a;
		*stack_a = (*stack_a)->next;
		first_node_a->next = *stack_b;
		*stack_b = first_node_a;
	}
	var->count_node_a = count_of_node(stack_a);
	var->count_node_b = count_of_node(stack_b);
	actual_position(stack_a);
	actual_position(stack_b);
	printf("pb\n");
}

void	do_pa(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	t_stack	*first_node_b;

	if (*stack_b)
	{
		first_node_b = *stack_b;
		*stack_b = (*stack_b)->next;
		first_node_b->next = *stack_a;
		*stack_a = first_node_b;
	}
	var->count_node_a = count_of_node(stack_a);
	var->count_node_b = count_of_node(stack_b);
	actual_position(stack_a);
	actual_position(stack_b);
	printf("pa\n");
}
