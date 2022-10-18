/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:02:56 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/13 12:41:26 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

long	ft_atol(char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	check_is_number(t_stack *stack_a, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack_a->arg[i][0] == '-' && stack_a->arg[i][1] == '\0')
	{
		if (var->use_split == 1)
			free_double_array(stack_a->arg);
		explore_free_exit(stack_a, var);
		exit_error();
	}
	while (stack_a->arg[i])
	{
		if (stack_a->arg[i][0] == '-')
			j++;
		while (stack_a->arg[i][j])
		{
			if (ft_isdigit(stack_a->arg[i][j]) == 1)
				free_error_program(stack_a, var);
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_int(t_stack *stack_a, t_var *var)
{
	int		i;
	long	temp;
	t_stack	*head;

	i = 0;
	head = stack_a;
	while (i < var->count_arg)
	{
		temp = ft_atol(head->arg[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			if (var->use_split == 1)
				free_double_array(head->arg);
			explore_free_exit(head, var);
			exit_error();
		}
		else
			stack_a->number = ft_atoi(head->arg[i]);
		i++;
		if (i == var->count_arg)
			stack_a->next = NULL;
		if (i != var->count_arg)
			create_node(&stack_a, var);
	}
	stack_a = head;
}

void	create_node(t_stack **stack_a, t_var *var)
{
	(*stack_a)->next = ft_calloc(sizeof (t_stack), 1);
	if (!(*stack_a)->next)
	{
		explore_free_exit(*stack_a, var);
		exit (1);
	}
	*stack_a = (*stack_a)->next;
}

void	check_duplicate(t_stack *stack_a, t_var *var)
{
	t_stack	*head;
	t_stack	*compare;

	head = stack_a;
	compare = stack_a;
	while (compare)
	{
		while (stack_a)
		{
			if (stack_a->next && compare->number == stack_a->next->number)
			{
				if (var->use_split == 1)
					free_double_array(head->arg);
				explore_free_exit(head, var);
				exit_error();
			}
			stack_a = stack_a->next;
		}
		compare = compare->next;
		stack_a = compare;
	}
	stack_a = head;
}
