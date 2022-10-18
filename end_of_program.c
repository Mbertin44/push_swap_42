/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:08:14 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/13 11:20:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	explore_free_exit(t_stack *stack, t_var *var)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free (stack);
		stack = NULL;
		stack = temp;
	}
	free(stack);
	free (var);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

/* Si la stack est déja trié, check_sorted retourne 0, sinon il renvoit 1. */

int	check_sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	stack = head;
	return (0);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_error_program(t_stack *stack, t_var *var)
{
	if (var->use_split == 1)
		free_double_array(stack->arg);
	free (var);
	free (stack);
	exit_error();
}
