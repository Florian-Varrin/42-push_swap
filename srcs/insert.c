/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:44:54 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:52:00 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

int	get_last_index(t_stack *stack, int rotation)
{
	if (rotation == 0)
		return (0);
	return (stack->top - rotation + 1);
}

int	get_rotation_number_to_insert(t_stack *stack, int number_to_insert)
{
	int		i;
	int		rotations;
	int		reverse_rotations;

	if (number_to_insert > stack_max_value(stack))
		i = stack_max_index(stack);
	else if (number_to_insert < stack_min_value(stack))
		i = stack_min_index(stack);
	else if (stack->arr[stack->top] > number_to_insert
		&& stack->arr[0] < number_to_insert)
		return (0);
	else
	{
		i = 0;
		while (!(stack->arr[i] > number_to_insert
				&& stack->arr[i + 1] < number_to_insert))
			i++;
	}
	reverse_rotations = i + 1;
	rotations = stack->top - i;
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (-reverse_rotations);
}

void	instert_in_ordered_stack(t_stack *stack_from, t_stack *stack_to)
{
	int		number_to_insert;
	int		rotations;

	while (stack_from->top != -1)
	{
		number_to_insert = stack_from->arr[stack_from->top];
		rotations = get_rotation_number_to_insert(
				stack_to,
				number_to_insert
				);
		if (rotations >= 0)
			rotate_n_times(stack_to, rotations, true);
		else
			reverse_rotate_n_times(stack_to, -rotations, true);
		push_stack(stack_from, stack_to, true);
	}
	rotate_ordered_to_be_sorted(stack_to);
}
