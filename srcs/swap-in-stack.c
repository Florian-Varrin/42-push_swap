/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap-in-stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:56:28 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/27 16:17:23 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

static void	_push_swap_push(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_stack(stack_a, stack_b);
	ft_swap_stack(stack_b);
	ft_push_stack(stack_b, stack_a);
}

int	ft_rotate_to_swap(t_stack *stack, int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
	{
		ft_rotate_n_times(stack, rotations);
		return (rotations);
	}
	else
	{
		ft_reverse_rotate_n_times(stack, reverse_rotations);
		return (-reverse_rotations);
	}
}

int	ft_swap_two_following_number(
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
		ft_reverse_rotate_stack(stack_a);
		ft_swap_stack(stack_a);
		return (-1);
	}
	rotations = stack_a->top - top_index;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	if (top_index - 1 == bottom_index)
		ft_swap_stack(stack_a);
	return (total_r);
}

int	ft_swap_two_number(
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
	if (bottom_index > top_index)
		ft_swap(&bottom_index, &top_index);
	total_r = 0;
	if ((top_index == stack_a->top && bottom_index == 0)
		|| top_index - 1 == bottom_index)
		return (ft_swap_two_following_number(stack_a, bottom_index, top_index));
	rotations = stack_a->top - top_index;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	ft_push_stack(stack_a, stack_b);
	rotations = stack_a->top - bottom_index - rotations;
	reverse_rotations = stack_a->top + 1 - rotations;
	total_r += ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	_push_swap_push(stack_a, stack_b);
	reverse_rotations = top_index - bottom_index - 1;
	rotations = stack_a->top + 1 - reverse_rotations;
	total_r += ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	ft_push_stack(stack_b, stack_a);
	if (total_r >= stack_a->top)
		return (total_r - stack_a->top);
	return (total_r);
}
