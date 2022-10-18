/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:16:24 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/07 15:16:14 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/*
	Décale d'une position vers le haut toute la pile A. Le premier devient le
	dernier.
*/

void	do_ra(t_stack **stack_a, t_var *var, int i)
{
	t_stack	*new_last;
	t_stack	*temp;

	if (*stack_a)
	{
		new_last = *stack_a;
		temp = (*stack_a)->next;
		*stack_a = temp;
		var->count_node_a = count_of_node(stack_a);
		temp = find_last_node_a(stack_a, var);
		temp->next = new_last;
		new_last->next = NULL;
		if (i == 0)
			printf("ra\n");
	}
	var->count_node_a = count_of_node(stack_a);
	actual_position(stack_a);
}

/*
	Décale d'une position vers le haut toute la pile B. Le premier devient le
	dernier.
*/

void	do_rb(t_stack **stack_b, t_var *var, int i)
{
	t_stack	*new_last;
	t_stack	*temp;

	if (*stack_b)
	{
		new_last = *stack_b;
		temp = (*stack_b)->next;
		*stack_b = temp;
		var->count_node_b = count_of_node(stack_b);
		temp = find_last_node_b(stack_b, var);
		temp->next = new_last;
		new_last->next = NULL;
		if (i == 0)
			printf("rb\n");
	}
	actual_position(stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	do_ra(stack_a, var, 1);
	do_rb(stack_b, var, 1);
	actual_position(stack_a);
	actual_position(stack_b);
	printf("rr\n");
}
