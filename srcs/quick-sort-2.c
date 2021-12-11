/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick-sort-2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:46:22 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 13:48:04 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h>

void	select_pivot(t_stack *stack, int *max_pivot, int *min_pivot)
{
	int		min_value;
	int		max_value;

	max_value = stack_max_value(stack);
	min_value = stack_min_value(stack);
	*max_pivot = (max_value + min_value) / 2;
	*min_pivot = (*max_pivot + min_value) / 2;
}

void	separate_chunks(t_stack *stack_from, t_stack *stack_to)
{
	int		operations;
	int		rotations;
	int		stack_size;
	int		min_pivot;
	int		max_pivot;

	if (stack_from->top <= 4)
	{
		ft_sort_until_five(stack_from, stack_to);
		return ;
	}
	select_pivot(stack_from, &max_pivot, &min_pivot);
	stack_size = stack_from->top + 1;
	operations = 0;
	rotations = 0;
	while (operations < stack_size)
	{
		if (stack_from->arr[stack_from->top] > max_pivot)
			ft_rotate_stack(stack_from);
		else
		{
			ft_push_stack(stack_from, stack_to);
			if (stack_to->arr[stack_to->top] > min_pivot)
			{
				ft_rotate_stack(stack_to);
				rotations++;
			}
		}
		operations++;
	}
	ft_reverse_rotate_n_times(stack_to, rotations);
	separate_chunks(stack_from, stack_to);
}

void	ft_sort_until_hundred(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_is_sorted(stack_a))
		return ;
	separate_chunks(stack_a, stack_b);
	ft_instert_in_ordered_stack(stack_b, stack_a);
}
