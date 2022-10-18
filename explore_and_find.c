/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore_and_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:21:53 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/06 11:43:48 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	count_arg(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->arg[i])
		i++;
	return (i);
}

int	count_of_node(t_stack **stack)
{
	t_stack	*head;
	int		i;

	head = *stack;
	i = 0;
	while (*stack)
	{
		i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (i);
}

int	find_median(t_stack **stack)
{
	int		i;
	t_stack	*head;

	head = *stack;
	i = 0;
	while (*stack)
	{
		if (i < (*stack)->index)
			i = (*stack)->index;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (i / 2);
}

int	get_bigger_index(t_stack *stack_a)
{
	int		index;
	t_stack	*head;

	index = 1;
	head = stack_a;
	while (stack_a)
	{
		if (stack_a->index > index)
			index = stack_a->index;
		stack_a = stack_a->next;
	}
	stack_a = head;
	return (index);
}

t_stack	*get_node_with_lower_index(t_stack *stack_a)
{
	int		index;
	t_stack	*head;
	t_stack	*temp;

	head = stack_a;
	index = INT_MAX;
	while (head)
	{
		if (head->index < index)
		{
			temp = head;
			index = head->index;
		}
		head = head->next;
	}
	return (temp);
}
