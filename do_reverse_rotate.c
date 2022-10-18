/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:26:44 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/11 13:59:27 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/*
	Décale d’une position vers le bas tous les éléments de la pile A.
	Le dernier élément devient le premier.
*/

void	do_rra(t_stack **stack, t_var *var, int i)
{
	t_stack	*last;
	t_stack	*temp;
	int		count_arg;

	var->count_node_a = count_of_node(stack);
	if (stack)
	{
		count_arg = var->count_arg;
		last = find_last_node_a(stack, var);
		last->next = (*stack);
		*stack = last;
		temp = find_last_node_a(stack, var);
		temp->next = NULL;
		if (i == 0)
			printf("rra\n");
	}
	actual_position(stack);
}

/*
	Décale d’une position vers le bas tous les éléments de la pile B.
	Le dernier élément devient le premier.
*/

void	do_rrb(t_stack **stack, t_var *var, int i)
{
	t_stack	*last;
	t_stack	*temp;

	if (stack)
	{
		last = find_last_node_b(stack, var);
		last->next = (*stack);
		*stack = last;
		temp = find_last_node_b(stack, var);
		temp->next = NULL;
		if (i == 0)
			printf("rrb\n");
	}
	actual_position(stack);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	do_rra(stack_a, var, 1);
	do_rrb(stack_b, var, 1);
	actual_position(stack_a);
	actual_position(stack_b);
	printf("rrr\n");
}
