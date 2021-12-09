/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 14:12:09 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack {
	char	identifier;
	int		size;
	int		top;
	int		*arr;
}	t_stack;

// General
void		ft_error(t_stack *stack_a, t_stack *stack_b);
void		ft_parse_arg(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
// Init
t_stack		*ft_create_stack(int size, char identifier);
t_stack		*ft_destroy_stack(t_stack *stack);
t_stack		*ft_init_stack(int size, char **content, char identifier);
// Operations
void		ft_push_stack(t_stack *stack_from, t_stack *stack_to);
void		ft_swap_stack(t_stack *stack);
void		ft_swap_both_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate_stack(t_stack *stack);
void		ft_rotate_both_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate_n_times(t_stack *stack, int n);
void		ft_reverse_rotate_stack(t_stack *stack);
void		ft_reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse_rotate_n_times(t_stack *stack, int n);
void		ft_instert_in_ordered_stack(t_stack *stack_from, t_stack *stack_to);
// Sorting
void		ft_sort_two(t_stack *stack);
void		ft_sort_three(t_stack *stack);
void		ft_sort_until_five(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_until_ten(t_stack *stack_a, t_stack *stack_b);
void		ft_sort_until_hundred(t_stack *stack_a, t_stack *stack_b);
// Utils
_Bool		stack_is_sorted(t_stack *stack);
_Bool		stack_is_ordered(t_stack *stack);
_Bool		partition_is_sorted(t_stack *stack, int start, int end);
int			stack_max_index(t_stack *stack);
int			stack_max_value(t_stack *stack);
int			stack_min_index(t_stack *stack);
int			stack_min_value(t_stack *stack);
void		ft_rotate_ordered_to_be_sorted(t_stack *stack);
int			ft_swap_two_number(t_stack *stack_a, t_stack *stack_b, int bottom_index, int top_index);
// Debug
void		ft_print_stack(t_stack *stack, char *message);
#endif
