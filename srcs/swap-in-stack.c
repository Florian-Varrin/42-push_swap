/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap-in-stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:56:28 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:45:36 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>

static void	_push_swap_push(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b, true);
	swap_stack(stack_b, true);
	push_stack(stack_b, stack_a, true);
}

int	rotate_to_swap(t_stack *stack, int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
	{
		rotate_n_times(stack, rotations, true);
		return (rotations);
	}
	else
	{
		reverse_rotate_n_times(stack, reverse_rotations, true);
		return (-reverse_rotations);
	}
}

int	swap_two_following_number(
			t_stack *stack_a,
			int bottom_index,
			int top_index
		)
{
	int		total_r;
	int		rotations;
	int		reverse_rotations;

	total_r = 0;
	if (top_index == stack_a->top && bottom_index == 0)
	{
		reverse_rotate_stack(stack_a, true);
		swap_stack(stack_a, true);
		return (-1);
	}
	rotations = stack_a->top - top_index;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += rotate_to_swap(stack_a, rotations, reverse_rotations);
	if (top_index - 1 == bottom_index)
		swap_stack(stack_a, true);
	return (total_r);
}

int	swap_two_number(
			t_stack *stack_a,
			t_stack *stack_b,
			int bottom_index,
			int top_index
		)
{
	int		total_r;
	int		rotations;
	int		reverse_rotations;

	if (bottom_index == top_index)
		return (0);
	total_r = 0;
	if ((top_index == stack_a->top && bottom_index == 0)
		|| top_index - 1 == bottom_index)
		return (swap_two_following_number(stack_a, bottom_index, top_index));
	rotations = stack_a->top - top_index;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += rotate_to_swap(stack_a, rotations, reverse_rotations);
	push_stack(stack_a, stack_b, true);
	rotations = stack_a->top - bottom_index - rotations;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += rotate_to_swap(stack_a, rotations, reverse_rotations);
	_push_swap_push(stack_a, stack_b);
	reverse_rotations = top_index - bottom_index - 1;
	rotations = stack_a->top + 1 - reverse_rotations;
	total_r += rotate_to_swap(stack_a, rotations, reverse_rotations);
	push_stack(stack_b, stack_a, true);
	return (total_r);
}
