
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:55:46 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/27 16:16:50 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>
#include <stdio.h>

int	ft_get_index(t_stack *stack, int index, int rotations)
{
	index += rotations;
	if (index < 0)
		index = stack->top + index + 1;
	else if (index > stack->top)
		index = index - stack->top - 1;
	return (index);
}

int	ft_partition(t_stack *stack_a, t_stack *stack_b, int *start, int *end, int *total_r)
{
	int		pivot;
	int		i;
	int		j;
	int		rotations;
	int		boundary;

	pivot = stack_a->arr[*end];
	boundary = *start - 1;
	i = *start;
	j = *end - *start - 1;
	while (j >= 0)
	{
		if (stack_a->arr[i] >= pivot)
		{
			printf("Swapping %d and %d\n", ft_get_index(stack_a, boundary + 1, 0), i);
			rotations = ft_swap_two_number(stack_a, stack_b, ft_get_index(stack_a, ++boundary, 0), i);
			ft_print_stack(stack_a, "After swap");
			i = ft_get_index(stack_a, i, rotations);
			boundary = ft_get_index(stack_a, boundary, rotations);
			*start = ft_get_index(stack_a, *start, rotations);
			*end = ft_get_index(stack_a, *end, rotations);
			*total_r += rotations;
		}
		i++;
		if (i == stack_a->top + 1)
			i = 0;
		j--;
	}
	boundary = ft_get_index(stack_a, boundary + 1, 0);
	printf("i %d\n", i);
	printf("boundary %d\n", boundary);
	rotations = ft_swap_two_number(stack_a, stack_b, i, boundary);
	boundary = ft_get_index(stack_a, boundary, rotations);
	*start = ft_get_index(stack_a, *start, rotations);
	*end = ft_get_index(stack_a, *end, rotations);
	*total_r += rotations;
	return (boundary);
}

int	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int		boundary;
	int		rotations;
	int		left_rotations;
	
	printf("quick start %d\n", start);
	printf("quick end %d\n", end);
	if (start >= end)
		return (0);
	rotations = 0;
	boundary = ft_partition(stack_a, stack_b, &start, &end, &rotations);
	/* printf("boundary %d\n", boundary); */
	ft_print_stack(stack_a, "After partition");
	/* printf("start %d\n", ft_get_index(stack_a, boundary + 1, 0)); */
	/* printf("end %d\n", end); */
	left_rotations = ft_quicksort(stack_a, stack_b, start, ft_get_index(stack_a, boundary - 1, 0));
	ft_quicksort(stack_a, stack_b, ft_get_index(stack_a, boundary + 1, left_rotations), ft_get_index(stack_a, end, left_rotations));
	return (rotations);
}

void	ft_sort_until_hundred(t_stack *stack_a, t_stack *stack_b)
{
	ft_quicksort(stack_a, stack_b, 0, stack_a->top);
	ft_rotate_ordered_to_be_sorted(stack_a);
}
