/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:36:49 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack {
	char	identifier;
	int		size;
	int		top;
	int		*arr;
}	t_stack;

// Error
void		error(t_stack *stack_a, t_stack *stack_b);
// Init
t_stack		*create_stack(int size, char identifier);
t_stack		*destroy_stack(t_stack *stack);
t_stack		*init_stack(int size, char **content, char identifier);
// Operations
void		push_stack(t_stack *stack_from, t_stack *stack_to, _Bool print_operation);
void		swap_stack(t_stack *stack, _Bool print_operation);
void		swap_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation);
void		rotate_stack(t_stack *stack, _Bool print_operation);
void		rotate_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation);
void		rotate_n_times(t_stack *stack, int n, _Bool print_operation);
void		reverse_rotate_stack(t_stack *stack, _Bool print_operation);
void		reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation);
void		reverse_rotate_n_times(t_stack *stack, int n, _Bool print_operation);
void		instert_in_ordered_stack(t_stack *stack_from, t_stack *stack_to);
// Utils
_Bool		stack_is_sorted(t_stack *stack);
_Bool		stack_is_ordered(t_stack *stack);
_Bool		partition_is_sorted(t_stack *stack, int start, int end);
int			stack_max_index(t_stack *stack);
int			stack_max_value(t_stack *stack);
int			stack_min_index(t_stack *stack);
int			stack_min_value(t_stack *stack);
// Debug
void		print_stack(t_stack *stack, char *message);
#endif
