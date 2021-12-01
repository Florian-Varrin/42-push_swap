/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:04:50 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/01 17:07:38 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>
#include <stdio.h>

int	ft_get_index(t_stack *stack, int index, int rotations)
{
	while (rotations > stack->top + 1)
		rotations -= stack->top + 1;
	while (rotations < 0)
		rotations += stack->top + 1;
	index += rotations;
	if (index < 0)
		index = stack->top + index + 1;
	else if (index > stack->top)
		index = index - stack->top - 1;
	return (index);
}

int	ft_partition(
		t_stack *stack_a,
		t_stack *stack_b,
		int start,
		int end,
		int *rotations
	)
{
	int		pivot;
	int		i;
	int		j;
	int		boundary;

	pivot = stack_a->arr[ft_get_index(stack_a, end, *rotations)];
	boundary = start - 1;
	i = start;
	j = end - start;
	while (j >= 0)
	{
		if (stack_a->arr[ft_get_index(stack_a, i, *rotations)] >= pivot)
			*rotations += ft_swap_two_number(stack_a, stack_b, ft_get_index(stack_a, ++boundary, *rotations), ft_get_index(stack_a, i, *rotations));
		i++;
		j--;
	}
	return (boundary);
}

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int			boundary;
	static int	rotations = 0;

	if (ft_get_index(stack_a, start, rotations) > ft_get_index(stack_a, end, rotations))
		return ;
	if (partition_is_sorted(stack_a, ft_get_index(stack_a, start, rotations), ft_get_index(stack_a, end, rotations)))
		return ;
	boundary = ft_partition(stack_a, stack_b, start, end, &rotations);
	ft_quicksort(stack_a, stack_b, start, boundary - 1);
	ft_quicksort(stack_a, stack_b, boundary + 1, end);
}

void	ft_sort_until_hundred(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_is_sorted(stack_a))
		return ;
	if (!stack_is_ordered(stack_a))
	{
		if (stack_max(stack_a) == stack_a->top)
			ft_reverse_rotate_stack(stack_a);
		ft_quicksort(stack_a, stack_b, 0, stack_a->top);
	}
	ft_rotate_ordered_to_be_sorted(stack_a);
}
