/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick-sort-2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:46:22 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 16:53:43 by fvarrin          ###   ########.fr       */
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

void	separate_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int		operations;
	int		rotations;
	int		stack_size;
	int		min_pivot;
	int		max_pivot;

	if (stack_a->top <= 4)
	{
		ft_sort_until_five(stack_a, stack_b);
		return ;
	}
	select_pivot(stack_a, &max_pivot, &min_pivot);
	stack_size = stack_a->top + 1;
	operations = 0;
	rotations = 0;
	while (operations < stack_size)
	{
		if (stack_a->arr[stack_a->top] > max_pivot)
		{
			ft_rotate_stack(stack_a);
			operations++;
		}
		else
		{
			ft_push_stack(stack_a, stack_b);
			if (stack_b->arr[stack_b->top] > min_pivot)
			{
				ft_rotate_stack(stack_b);
				rotations++;
			}
			operations++;
		}
	}
	ft_reverse_rotate_n_times(stack_b, rotations);
	/* ft_print_stack(stack_a, "After separate"); */
	separate_chunks(stack_a, stack_b);
}

void	ft_sort_until_hundred(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_is_sorted(stack_a))
		return ;
	separate_chunks(stack_a, stack_b);
	ft_instert_in_ordered_stack(stack_b, stack_a);
	/* ft_printf("max_pivot %d\n", max_pivot); */
	/* ft_printf("min_pivot %d\n", min_pivot); */
}
