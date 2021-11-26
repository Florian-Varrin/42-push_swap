/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:00:02 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/26 17:02:38 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_rotate_to_swap(t_stack *stack, int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
		ft_rotate_n_times(stack, rotations);
	else
		ft_reverse_rotate_n_times(stack, reverse_rotations);
}

void	ft_swap_two_number(
			t_stack *stack_a,
			t_stack *stack_b,
			int bottom_index,
			int top_index
		)
{
	int		rotations;
	int		reverse_rotations;

	if (top_index == stack_a->top && bottom_index == 0)
	{
		ft_reverse_rotate_stack(stack_a);
		return (ft_swap_stack(stack_a));
	}
	rotations = stack_a->top - top_index;
	reverse_rotations = stack_a->top + 1 - rotations;
	ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	if (top_index - 1 == bottom_index)
		return (ft_swap_stack(stack_a));
	ft_push_stack(stack_a, stack_b);
	rotations = stack_a->top - bottom_index - rotations;
	reverse_rotations = stack_a->top + 1 - rotations;
	ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	ft_push_stack(stack_a, stack_b);
	ft_swap_stack(stack_b);
	ft_push_stack(stack_b, stack_a);
	reverse_rotations = top_index - bottom_index - 1;
	rotations = stack_a->top + 1 - reverse_rotations;
	ft_rotate_to_swap(stack_a, rotations, reverse_rotations);
	ft_push_stack(stack_b, stack_a);
}
