/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 17:22:39 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack {
	char	identifier;
	int		size;
	int		top;
	int		*arr;
	int		*sorted_arr;
	int		*original_arr;
}	t_stack;

typedef struct s_instruction_el
{
	char	*instruction;
	char	stack_identifier;
}	t_instruction_el;

// Parsing
void				parse_arg(t_stack **stack_a, t_stack **stack_b,
						int argc, char **argv);

// Error
void				exit_error(t_stack *stack_a, t_stack *stack_b);

// Init
t_stack				*create_stack(int size, char identifier);
t_stack				*destroy_stack(t_stack *stack);
t_stack				*init_stack(int size, char **content, char identifier);
t_stack				*reset_stack(t_stack *stack);

// Operations
void				push_stack(t_stack *stack_from, t_stack *stack_to,
						t_list_el **lst);
void				swap_stack(t_stack *stack, t_list_el **lst);
void				swap_both_stack(t_stack *stack_a, t_stack *stack_b,
						t_list_el **lst);
void				rotate_stack(t_stack *stack, t_list_el **lst);
void				rotate_both_stack(t_stack *stack_a, t_stack *stack_b,
						t_list_el **lst);
void				rotate_n_times(t_stack *stack, int n, t_list_el **lst);
void				reverse_rotate_stack(t_stack *stack, t_list_el **lst);
void				reverse_rotate_both_stack(t_stack *stack_a,
						t_stack *stack_b, t_list_el **lst);
void				reverse_rotate_n_times(t_stack *stack, int n,
						t_list_el **lst);
void				instert_in_ordered_stack(t_stack *stack_from,
						t_stack *stack_to, t_list_el **lst);
void				instert_in_empty_stack(t_stack *stack_from,
						t_stack *stack_to, t_list_el **lst);

// Utils
_Bool				stack_is_sorted(t_stack *stack);
_Bool				stack_is_ordered(t_stack *stack);
_Bool				partition_is_sorted(t_stack *stack, int start, int end);
int					stack_max_index(t_stack *stack);
int					stack_max_value(t_stack *stack);
int					stack_min_index(t_stack *stack);
int					stack_min_value(t_stack *stack);
int					get_number_index(t_stack *stack, int number);
_Bool				top_value_greater_bellow(t_stack *stack);

// Getter
int					stack_top_value(t_stack *stack);
int					stack_value(t_stack *stack, int index);

// Instructions
t_instruction_el	*create_instruction_el(char instruction[3],
						char stack_identifier);
void				print_instructions(void *instruction_input);
void				destroy_instruction_el(void *instruction_input);
int					optimise_instructions(t_list_el **lst);
int					count_instructions(t_list_el *lst);
_Bool				instruction_is_push(char *instruction);
void				get_both_instruction_value(char *instruction,
						char *both_instructions);

// Debug
void				print_stack(t_stack *stack, char *message);

#endif
