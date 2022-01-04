/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert-empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:38:47 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 15:11:08 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

int		get_next_number_to_insert(int *sorted_arr, int last_number)
{
	int		i;

	i = 0;
	while (sorted_arr[i] != last_number)
		i++;
	if (i == 0)
		return (sorted_arr[i]);
	else
		return (sorted_arr[i - 1]);
}

int	get_rotation_number_to_top(t_stack *stack, int number)
{
	int		number_index;
	int		rotations;
	int		reverse_rotations;

	number_index = get_number_index(stack, number);
	rotations = stack->top - number_index;
	reverse_rotations = stack->top - rotations + 1;
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (-reverse_rotations);
}

void	instert_in_empty_stack(
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	int		number_to_insert;
	int		next_number_to_insert;
	int		rotations;
	int		i;
	_Bool	need_to_swap;

	while (stack_from->top != -1)
	{
		if (stack_to->top == -1)
			number_to_insert = stack_max_value(stack_from);
		else
			number_to_insert = get_next_number_to_insert(stack_to->sorted_arr, stack_to->arr[stack_to->top]);
		next_number_to_insert = get_next_number_to_insert(stack_to->sorted_arr, number_to_insert);
		rotations = get_rotation_number_to_top(stack_from, number_to_insert);
		i = 0;
		need_to_swap = false;
		if (rotations >= 0)
		{
			while (i < rotations)
			{
				rotate_stack(stack_from, lst);
				i++;
				if (stack_from->arr[stack_from->top] == next_number_to_insert && number_to_insert != next_number_to_insert)
				{
					push_stack(stack_from, stack_to, lst);
					need_to_swap = true;
					i++;
				}
			}
		}
		else
		{
			rotations = rotations * -1;
			while (i < rotations)
			{
				if (stack_from->arr[stack_from->top] == next_number_to_insert && number_to_insert != next_number_to_insert)
				{
					push_stack(stack_from, stack_to, lst);
					need_to_swap = true;
				}
				reverse_rotate_stack(stack_from, lst);
				i++;
			}
		}
		push_stack(stack_from, stack_to, lst);
		if (need_to_swap)
		{
			swap_stack(stack_to, lst);
			if (stack_from->top > 0 && stack_from->arr[stack_from->top] < stack_from->arr[stack_from->top - 1])
				swap_stack(stack_from, lst);
		}
	}
}
