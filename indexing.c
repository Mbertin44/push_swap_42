/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:14:03 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/04 09:49:41 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	actual_position(t_stack **stack)
{
	t_stack	*head;
	t_stack	*comp;

	head = *stack;
	comp = *stack;
	while (comp)
	{
		comp->pos = 0;
		while (comp->number != head->number)
		{
			comp->pos++;
			head = head->next;
		}
		comp = comp->next;
		head = *stack;
	}
}

void	index_final_pos(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*comp;

	head = stack_a;
	while (stack_a)
	{
		stack_a->index = 1;
		comp = head;
		while (comp)
		{
			if (stack_a->number > comp->number)
				stack_a->index++;
			comp = comp->next;
		}
		stack_a = stack_a->next;
	}
	stack_a = head;
}

void	target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = *stack_b;
	while (*stack_b)
	{
		do_target_pos(stack_a, stack_b, INT_MAX);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head;
}

// Initialise la position cible des maillons de stack_b vers stack_a

void	do_target_pos(t_stack **stack_a, t_stack **stack_b, int previous_index)
{
	t_stack	*head_a;
	t_stack	*temp;

	head_a = *stack_a;
	while (*stack_a)
	{
		if ((*stack_a)->index > (*stack_b)->index
			&& (*stack_a)->index < previous_index)
		{
			previous_index = (*stack_a)->index;
			(*stack_b)->target_pos = (*stack_a)->pos;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head_a;
	if (previous_index != INT_MAX)
		return ;
	if (*stack_b && (*stack_a)->index < (*stack_b)->index)
	{
		temp = get_node_with_lower_index(*stack_a);
		(*stack_b)->target_pos = temp->pos;
	}
}
