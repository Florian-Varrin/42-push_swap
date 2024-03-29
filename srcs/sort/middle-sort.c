/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:46:22 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 15:57:45 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

static void	_init_vars(
			t_stack *stack_from,
			int *stack_size,
			int *operations,
			int *rotations
		)
{
	*stack_size = stack_from->top + 1;
	*operations = 0;
	*rotations = 0;
}

static void	_rotate_stack_and_inc(
		t_stack *stack,
		int *rotations,
		t_list_el **lst
	)
{
	if (stack->top > 0)
	{
		rotate_stack(stack, lst);
		(*rotations)++;
	}
}

static void	_reverse_rotate_back(
		int rotations,
		t_stack *stack_from,
		t_stack *stack_to,
		t_list_el **lst
	)
{
	while (rotations > 0)
	{
		reverse_rotate_stack(stack_to, lst);
		if (stack_value(stack_from, 0) > stack_top_value(stack_from))
			reverse_rotate_stack(stack_from, lst);
		rotations--;
	}
}

void	separate_chunks_by_pivot(
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	int		operations;
	int		rotations;
	int		stack_size;
	int		min_pivot;
	int		max_pivot;

	if (stack_from->top == -1)
		return ;
	_init_vars(stack_from, &stack_size, &operations, &rotations);
	select_pivot(stack_from, &max_pivot, &min_pivot);
	while (operations < stack_size)
	{
		if (stack_top_value(stack_from) > max_pivot)
			rotate_stack(stack_from, lst);
		else
		{
			push_stack(stack_from, stack_to, lst);
			if (stack_top_value(stack_to) > min_pivot)
				_rotate_stack_and_inc(stack_to, &rotations, lst);
		}
		operations++;
	}
	_reverse_rotate_back(rotations, stack_from, stack_to, lst);
	separate_chunks_by_pivot(stack_from, stack_to, lst);
}

void	sort_until_four_hundred(
		t_stack *stack_a,
		t_stack *stack_b,
		t_list_el **lst
	)
{
	if (stack_is_sorted(stack_a))
		return ;
	separate_chunks_by_pivot(stack_a, stack_b, lst);
	instert_in_empty_stack(stack_b, stack_a, lst);
}
