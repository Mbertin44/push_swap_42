/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:14:53 by mbertin           #+#    #+#             */
/*   Updated: 2022/10/13 11:13:05 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

//--------------------------------	STRUCTURE	--------------------------

typedef struct s_stack
{
	char				**arg;
	int					number;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
}	t_stack;

typedef struct s_var
{
	int					use_split;
	int					count_arg;
	int					count_node_a;
	int					count_node_b;
}	t_var;

//---------------------------	EXPLORE	--------------------------

int		count_arg(t_stack *stack_a);
int		count_of_node(t_stack **stack);
int		find_median(t_stack **stack);
t_stack	*find_last_node_a(t_stack **stack, t_var *var);
t_stack	*find_last_node_b(t_stack **stack, t_var *var);
t_stack	*get_node_with_lower_index(t_stack *stack_a);
void	explore_free_exit(t_stack *stack, t_var *var);
void	free_error_program(t_stack *stack, t_var *var);
void	free_double_array(char **array);
void	exit_error(void);
int		get_bigger_index(t_stack *stack_a);
int		abs_value(int cost);

//-----------------------------		INDEXING	------------------------

void	actual_position(t_stack **stack);
void	index_final_pos(t_stack *stack_a);
void	target_pos(t_stack **stack_a, t_stack **stack_b);
void	do_target_pos(t_stack **stack_a, t_stack **stack_b, int previous_index);
void	get_cost(t_stack **stack_b, t_var *var);

//--------------------------------	PARSING	----------------------------

void	check_is_number(t_stack *stack_a, t_var *var);
void	check_int(t_stack *stack_a, t_var *var);
void	create_node(t_stack **stack_a, t_var *var);
void	check_duplicate(t_stack *stack_a, t_var *var);
long	ft_atol(char *str);
int		ft_char_is_digit(char c);
int		check_sorted(t_stack *stack);
void	malloc_structure(t_stack **stack_a, t_var **var);

//--------------------------------	SORTING	----------------------------------

t_stack	*push_swap_one_arg(t_stack *stack_a, t_stack *stack_b,
			t_var *var, char **argv);
void	first_push_to_b(t_stack **stack_a, t_stack **stack_b, t_var *var);
void	first_push_to_b_five(t_stack **stack_a, t_stack **stack_b, t_var *var);
void	sort_three_value(t_stack **stack_a, t_var *var);
void	sorting_more_than_five_value(t_stack **stack_a,
			t_stack **stack_b, t_var *var);
void	find_cheapest_move(t_stack **stack_a, t_stack **stack_b, t_var *var);
void	sorting(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node, t_var *var);
void	sorting_rr(t_stack **stack_a, t_stack **stack_b,
			t_var *var, t_stack *cheapest_node);
void	sorting_rrr(t_stack **stack_a, t_stack **stack_b,
			t_var *var, t_stack *cheapest_node);
void	sorting_a(t_stack **stack_a, t_var *var, t_stack *cheapest_node);
void	sorting_b(t_stack **stack_b, t_var *var, t_stack *cheapest_node);
void	sorting_of_five(t_stack **stack_a, t_stack **stack_b, t_var *var);

//--------------------------------	DEPLACEMENTS	--------------------------

// ROTATE :

void	do_rra(t_stack **stack, t_var *var, int i);
void	do_rrb(t_stack **stack, t_var *var, int i);
void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_var *var);

// REVERSE ROTATE :

void	do_ra(t_stack **stack_a, t_var *var, int i);
void	do_rb(t_stack **stack_b, t_var *var, int i);
void	do_rr(t_stack **stack_a, t_stack **stack_b, t_var *var);

// SWAP :

void	do_sa(t_stack **stack_a, int i);
void	do_sb(t_stack **stack, int i);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

// PUSH TO :

void	do_pb(t_stack **stack_a, t_stack **stack_b, t_var *var);
void	do_pa(t_stack **stack_a, t_stack **stack_b, t_var *var);

#endif
