/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 17:47:16 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stack.h"
#include "libft.h"

#define CHUNK_SIZE 43

// Sorting
void		sort_two(t_stack *stack, t_list_el **lst);
void		sort_three(t_stack *stack, t_list_el **lst);
void		sort_until_five(t_stack *stack_a, t_stack *stack_b, t_list_el **lst);
void		sort_until_four_hundred(t_stack *stack_a, t_stack *stack_b, t_list_el **lst);
void		sort_after_four_hundred(t_stack *stack_a, t_stack *stack_b, t_list_el **lst);

// Utils
_Bool		stack_is_sorted(t_stack *stack);
_Bool		stack_is_ordered(t_stack *stack);
_Bool		partition_is_sorted(t_stack *stack, int start, int end);
int			stack_max_index(t_stack *stack);
int			stack_max_value(t_stack *stack);
int			stack_min_index(t_stack *stack);
int			stack_min_value(t_stack *stack);
void		rotate_ordered_to_be_sorted(t_stack *stack, t_list_el **lst);
int			swap_two_number(t_stack *stack_a, t_stack *stack_b, int bottom_index, int top_index);
#endif
