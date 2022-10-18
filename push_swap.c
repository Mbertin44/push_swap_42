/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:12:54 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/13 11:14:40 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	malloc_structure(t_stack **stack_a, t_var **var)
{
	*var = ft_calloc(1, sizeof(t_var));
	if (!(*var))
		exit (1);
	*stack_a = ft_calloc(1, sizeof(t_stack));
	if (!(*stack_a))
		exit (1);
}

t_stack	*check_params_and_sort(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	check_is_number(stack_a, var);
	check_int(stack_a, var);
	check_duplicate(stack_a, var);
	if (check_sorted(stack_a) == 0)
		return (stack_a);
	index_final_pos(stack_a);
	actual_position(&stack_a);
	if (var->count_arg == 2)
		do_ra(&stack_a, var, 0);
	else if (var->count_arg == 3)
		sort_three_value(&stack_a, var);
	else if (var->count_arg == 5)
		sorting_of_five(&stack_a, &stack_b, var);
	else
		sorting_more_than_five_value(&stack_a, &stack_b, var);
	return (stack_a);
}

t_stack	*push_swap_one_arg(t_stack *stack_a, t_stack *stack_b,
			t_var *var, char **argv)
{
	t_stack	*head;

	stack_a->arg = ft_split(argv[1], ' ');
	if (stack_a->arg[0] == NULL)
		free_double_array(stack_a->arg);
	var->use_split = 1;
	var->count_arg = count_arg(stack_a);
	head = check_params_and_sort(stack_a, stack_b, var);
	free_double_array(stack_a->arg);
	return (head);
}

void	sorting_more_than_five_value(t_stack **stack_a,
		t_stack **stack_b, t_var *var)
{
	first_push_to_b(stack_a, stack_b, var);
	sort_three_value(stack_a, var);
	while (*stack_b)
	{
		target_pos(stack_a, stack_b);
		get_cost(stack_b, var);
		find_cheapest_move(stack_a, stack_b, var);
	}
	while (check_sorted(*stack_a) != 0)
		do_ra(stack_a, var, 0);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*head;
	t_var		*var;

	stack_a = NULL;
	stack_b = NULL;
	head = NULL;
	var = NULL;
	if (argc == 1)
		return (0);
	malloc_structure(&stack_a, &var);
	var->count_arg = argc - 1;
	if (argc == 2)
		head = push_swap_one_arg(stack_a, stack_b, var, argv);
	else if (argc > 2)
	{
		stack_a->arg = &argv[1];
		stack_a->arg[argc] = "\0";
		head = check_params_and_sort(stack_a, stack_b, var);
	}
	explore_free_exit(head, var);
	return (0);
}

/*
						---------------- PROBLEME ACTUEL ------------------



./push_swap "89364982739487293874293874 3 2 1"

une seule valeur over min\max int leak

*/