/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:15:58 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/11 13:59:32 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*find_last_node_a(t_stack **stack, t_var *var)
{
	t_stack	*head;
	t_stack	*temp;
	int		i;

	i = 1;
	head = *stack;
	if (var->count_node_a == 2)
		return ((*stack)->next);
	else
	{
		while (i != var->count_node_a)
		{
			*stack = (*stack)->next;
			i++;
		}
		temp = *stack;
		*stack = head;
		return (temp);
	}
}

t_stack	*find_last_node_b(t_stack **stack, t_var *var)
{
	t_stack	*head;
	t_stack	*temp;
	int		i;

	i = 1;
	head = *stack;
	if (var->count_node_b == 2)
		return ((*stack)->next);
	else
	{
		while (i != var->count_node_b)
		{
			*stack = (*stack)->next;
			i++;
		}
		temp = *stack;
		*stack = head;
		return (temp);
	}
}
