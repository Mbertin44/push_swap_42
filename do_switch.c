/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:14:35 by mbertin           #+#    #+#             */
/*   Updated: 2022/09/27 14:54:18 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Intervertit les 2 premiers éléments au sommet de la pile A.

void	do_sa(t_stack **stack, int i)
{
	int	temp;

	temp = (*stack)->number;
	if (*stack)
	{
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->number = temp;
		temp = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = temp;
	}
	if (i == 0)
		printf("sa\n");
	actual_position(stack);
}

// Intervertit les 2 premiers éléments au sommet de la pile A.

void	do_sb(t_stack **stack, int i)
{
	int	temp;

	temp = (*stack)->number;
	if (*stack)
	{
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->number = temp;
		temp = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = temp;
	}
	if (i == 0)
		printf("sb\n");
	actual_position(stack);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a, 1);
	do_sb(stack_b, 1);
	actual_position(stack_a);
	actual_position(stack_b);
	printf("ss\n");
}
