/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:02:55 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 18:08:16 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	get_next_indexes(t_stack *stack_from, int chunk_start, int *top_number_index, int *bottom_number_index)
{
	int		i;
	int		j;

	i = stack_from->top;
	j = chunk_start;
	while (*top_number_index == -1)
	{
		while (j < chunk_start + CHUNK_SIZE)
		{
			if (stack_from->arr[i] == stack_from->sorted_arr[j])
			{
				*top_number_index = i;
				break ;
			}
			j++;
		}
		i--;
		j = chunk_start;
	}
	i = 0;
	j = chunk_start;
	while (*bottom_number_index == -1)
	{
		while (j < chunk_start + CHUNK_SIZE)
		{
			if (stack_from->arr[i] == stack_from->sorted_arr[j])
			{
				*bottom_number_index = i;
				break ;
			}
			j++;
		}
		i++;
		j = chunk_start;
	}
}

static void	separate_chunks(t_stack *stack_from, t_stack *stack_to, int chunk_start, t_list_el **lst)
{
	int		rotations;
	int		reverse_rotations;
	int		pushed;

	if (chunk_start > stack_from->size)
		return ;
	pushed = 0;
	while (pushed < CHUNK_SIZE)
	{
		rotations = -1;
		reverse_rotations = -1;
		get_next_indexes(stack_from, chunk_start, &rotations, &reverse_rotations);
		rotations = stack_from->top - rotations;
		reverse_rotations = reverse_rotations + 1;
		if (rotations <= reverse_rotations)
			rotate_n_times(stack_from, rotations, lst);
		else
			reverse_rotate_n_times(stack_from, reverse_rotations, lst);
		push_stack(stack_from, stack_to, lst);
		pushed++;
	}
	separate_chunks(stack_from, stack_to, chunk_start + CHUNK_SIZE , lst);
}

void	sort_after_four_hundred(t_stack *stack_a, t_stack *stack_b, t_list_el **lst)
{
	if (stack_is_sorted(stack_a))
		return ;
	separate_chunks(stack_a, stack_b, 0, lst);
	instert_in_empty_stack(stack_b, stack_a, lst);
}
