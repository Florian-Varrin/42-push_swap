/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 17:23:28 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "libft.h"

# define CHUNK_NUMBERS_START 14
# define CHUNK_NUMBERS_END 32

// Sorting
void		sort_two(t_stack *stack, t_list_el **lst);
void		sort_three(t_stack *stack, t_list_el **lst);
void		sort_until_five(t_stack *stack_a, t_stack *stack_b,
				t_list_el **lst);
void		sort_until_four_hundred(t_stack *stack_a, t_stack *stack_b,
				t_list_el **lst);
void		sort_after_four_hundred(t_stack *stack_a, t_stack *stack_b,
				t_list_el **lst);

// Chunks
void		separate_chunks_by_pivot(t_stack *stack_from, t_stack *stack_to,
				t_list_el **lst);
void		separate_chunks_by_size(t_stack *stack_from, t_stack *stack_to,
				int chunk_infos[2], t_list_el **lst);

// Utils
_Bool		stack_is_sorted(t_stack *stack);
_Bool		stack_is_ordered(t_stack *stack);
_Bool		partition_is_sorted(t_stack *stack, int start, int end);
int			stack_max_index(t_stack *stack);
int			stack_max_value(t_stack *stack);
int			stack_min_index(t_stack *stack);
int			stack_min_value(t_stack *stack);
void		rotate_ordered_to_be_sorted(t_stack *stack, t_list_el **lst);
int			swap_two_number(t_stack *stack_a, t_stack *stack_b,
				int bottom_index, int top_index);
void		select_pivot(t_stack *stack, int *max_pivot, int *min_pivot);
void		get_next_indexes(t_stack *stack_from, int chunk_infos[2],
				int *top_number_index, int *bottom_number_index);
int			get_next_number_to_insert(int *sorted_arr, int last_number);
int			get_rotation_number_to_top(t_stack *stack, int number);
#endif
