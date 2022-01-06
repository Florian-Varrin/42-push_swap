/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert-sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:44:54 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 15:07:53 by fvarrin          ###   ########.fr       */
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

static int	_get_rotation_special_case(t_stack *stack, int number_to_insert)
{
	int		i;
	int		rotations;
	int		reverse_rotations;

	if (number_to_insert > stack_max_value(stack))
	{
		i = stack_max_index(stack);
		reverse_rotations = i;
		rotations = stack->top - i + 1;
	}
	else if (number_to_insert < stack_min_value(stack))
	{
		i = stack_min_index(stack);
		reverse_rotations = i + 1;
		rotations = stack->top - i;
	}
	else
		return (0);
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (-reverse_rotations);
}

int	get_rotation_number_to_insert(t_stack *stack, int number_to_insert)
{
	int		i;
	int		rotations;
	int		reverse_rotations;

	if (number_to_insert > stack_max_value(stack))
		return (_get_rotation_special_case(stack, number_to_insert));
	else if (number_to_insert < stack_min_value(stack))
		return (_get_rotation_special_case(stack, number_to_insert));
	else if (stack_top_value(stack) > number_to_insert
		&& stack_value(stack, 0) < number_to_insert)
		return (0);
	else
	{
		i = 0;
		while (!(stack_value(stack, i) > number_to_insert
				&& stack_value(stack, i + 1) < number_to_insert))
			i++;
		reverse_rotations = i + 1;
		rotations = stack->top - i;
	}
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (-reverse_rotations);
}

void	instert_in_ordered_stack(
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	int		number_to_insert;
	int		rotations;

	while (stack_from->top != -1)
	{
		if (stack_from->top > 0 && top_value_greater_bellow(stack_from)
			&& stack_min_index(stack_from) == stack_from->top)
		{
			swap_stack(stack_from, lst);
			continue ;
		}
		number_to_insert = stack_top_value(stack_from);
		rotations = get_rotation_number_to_insert(
				stack_to,
				number_to_insert
				);
		if (rotations >= 0)
			rotate_n_times(stack_to, rotations, lst);
		else
			reverse_rotate_n_times(stack_to, -rotations, lst);
		push_stack(stack_from, stack_to, lst);
	}
	rotate_ordered_to_be_sorted(stack_to, lst);
}
