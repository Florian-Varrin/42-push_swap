/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert-empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:38:47 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 16:30:02 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

static void	_set_numbers_to_insert(
		t_stack *stack_from,
		t_stack *stack_to,
		int *number_to_insert,
		int *next_number_to_insert
	)
{
	int		*sorted_arr;

	sorted_arr = stack_to->sorted_arr;
	if (stack_to->top == -1)
		*number_to_insert = stack_max_value(stack_from);
	else
		*number_to_insert = get_next_number_to_insert(
				sorted_arr, stack_top_value(stack_to));
	*next_number_to_insert = get_next_number_to_insert(
			sorted_arr, *number_to_insert);
}

static void	_push_and_swap(
			_Bool need_to_swap,
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	push_stack(stack_from, stack_to, lst);
	if (need_to_swap)
	{
		swap_stack(stack_to, lst);
		if (stack_from->top > 0 && top_value_greater_bellow(stack_from))
			swap_stack(stack_from, lst);
	}
}

static _Bool	_handle_rotations(
			t_stack *stacks[2],
			int rotations,
			int next_number_to_insert,
			t_list_el **lst
		)
{
	int		i;
	_Bool	need_to_swap;
	t_stack	*stack_from;
	t_stack	*stack_to;

	i = 0;
	stack_from = stacks[0];
	stack_to = stacks[1];
	need_to_swap = false;
	while (i < rotations)
	{
		rotate_stack(stack_from, lst);
		i++;
		if (stack_top_value(stack_from) == next_number_to_insert)
		{
			push_stack(stack_from, stack_to, lst);
			i++;
			need_to_swap = true;
		}
	}
	return (need_to_swap);
}

static _Bool	_handle_reverse_rotations(
			t_stack *stacks[2],
			int rotations,
			int next_number_to_insert,
			t_list_el **lst
		)
{
	int		i;
	_Bool	need_to_swap;
	t_stack	*stack_from;
	t_stack	*stack_to;

	i = 0;
	stack_from = stacks[0];
	stack_to = stacks[1];
	need_to_swap = false;
	rotations = rotations * -1;
	while (i < rotations)
	{
		if (stack_top_value(stack_from) == next_number_to_insert)
		{
			push_stack(stack_from, stack_to, lst);
			need_to_swap = true;
		}
		reverse_rotate_stack(stack_from, lst);
		i++;
	}
	return (need_to_swap);
}

void	instert_in_empty_stack(
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	int		num_to_insert;
	int		next_num_to_insert;
	int		rotations;
	_Bool	need_to_swap;
	t_stack	*stacks[2];

	stacks[0] = stack_from;
	stacks[1] = stack_to;
	while (stack_from->top != -1)
	{
		_set_numbers_to_insert(
			stack_from, stack_to, &num_to_insert, &next_num_to_insert);
		rotations = get_rotation_number_to_top(stack_from, num_to_insert);
		need_to_swap = false;
		if (rotations >= 0)
			need_to_swap = _handle_rotations(
					stacks, rotations, next_num_to_insert, lst);
		else
			need_to_swap = _handle_reverse_rotations(
					stacks, rotations, next_num_to_insert, lst);
		_push_and_swap(need_to_swap, stack_from, stack_to, lst);
	}
}
