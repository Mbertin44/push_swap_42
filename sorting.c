/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:39 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/11 14:37:03 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest_node, t_var *var)
{
	if (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
		sorting_rr(stack_a, stack_b, var, cheapest_node);
	else if (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
		sorting_rrr(stack_a, stack_b, var, cheapest_node);
	if (cheapest_node->cost_a != 0)
		sorting_a(stack_a, var, cheapest_node);
	if (cheapest_node->cost_b != 0)
		sorting_b(stack_b, var, cheapest_node);
	do_pa(stack_a, stack_b, var);
}

void	sorting_rr(t_stack **stack_a, t_stack **stack_b,
	t_var *var, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		do_rr(stack_a, stack_b, var);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
}

void	sorting_rrr(t_stack **stack_a, t_stack **stack_b,
			t_var *var, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		do_rrr(stack_a, stack_b, var);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

void	sorting_a(t_stack **stack_a, t_var *var, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a != 0)
	{
		if (cheapest_node->cost_a < 0)
		{
			do_rra(stack_a, var, 0);
			cheapest_node->cost_a++;
		}
		if (cheapest_node->cost_a > 0)
		{
			do_ra(stack_a, var, 0);
			cheapest_node->cost_a--;
		}
	}
}

void	sorting_b(t_stack **stack_b, t_var *var, t_stack *cheapest_node)
{
	while (cheapest_node->cost_b != 0)
	{
		if (cheapest_node->cost_b < 0)
		{
			do_rrb(stack_b, var, 0);
			cheapest_node->cost_b++;
		}
		if (cheapest_node->cost_b > 0)
		{
			do_rb(stack_b, var, 0);
			cheapest_node->cost_b--;
		}
	}
}
