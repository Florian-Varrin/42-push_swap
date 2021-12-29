/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:46:22 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/28 14:26:53 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	select_pivot(t_stack *stack, int *max_pivot, int *min_pivot)
{
	int		min_value;
	int		max_value;

	max_value = stack_max_value(stack);
	min_value = stack_min_value(stack);
	*max_pivot = (max_value + min_value) / 2;
	*min_pivot = (*max_pivot + min_value) / 2;
}

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

static void	_rotate_stack_and_inc(t_stack *stack, int *rotations, t_list_el **lst)
{
	if (stack->top > 0)
	{
		rotate_stack(stack, lst);
		(*rotations)++;
	}
}

void	separate_chunks(t_stack *stack_from, t_stack *stack_to, t_list_el **lst)
{
	int		operations;
	int		rotations;
	int		stack_size;
	int		min_pivot;
	int		max_pivot;

	if (stack_from->top <= 2)
		return (sort_three(stack_from, lst));
	_init_vars(stack_from, &stack_size, &operations, &rotations);
	select_pivot(stack_from, &max_pivot, &min_pivot);
	while (operations < stack_size)
	{
		if (stack_from->arr[stack_from->top] > max_pivot)
			rotate_stack(stack_from, lst);
		else
		{
			push_stack(stack_from, stack_to, lst);
			if (stack_to->arr[stack_to->top] > min_pivot)
				_rotate_stack_and_inc(stack_to, &rotations, lst);
			/* else if (stack_to->top > 0 && stack_to->arr[stack_to->top] < stack_to->arr[stack_to->top - 1]) */
			/* 	swap_stack(stack_to, lst); */
		}
		operations++;
	}
	reverse_rotate_n_times(stack_to, rotations, lst);
	separate_chunks(stack_from, stack_to, lst);
}

void	sort_until_hundred(t_stack *stack_a, t_stack *stack_b, t_list_el **lst)
{
	if (stack_is_sorted(stack_a))
		return ;
	separate_chunks(stack_a, stack_b, lst);
	instert_in_ordered_stack(stack_b, stack_a, lst);
}
