/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:44:54 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/18 16:55:22 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_instert_in_sorted_stack(t_stack *stack_from, t_stack *stack_to)
{
	int		number_to_insert;
	int		i_bottom;
	int		i_top;
	int		min_index;

	while (stack_from->top != -1)
	{
		number_to_insert = stack_from->arr[stack_from->top];
		i_top = 0;
		while (stack_to->arr[stack_to->top - i_top] < number_to_insert || i_top == (stack_to->size - 1))
			i_top++;
		i_bottom = 0;
		while (stack_to->arr[i_bottom] > number_to_insert || i_bottom == (stack_to->size - 1))
			i_bottom++;
		printf("");
		if (i_top <= i_bottom)
			ft_reverse_rotate_n_times(stack_to, i_top);
		else 
			ft_rotate_n_times(stack_to, i_bottom);
		ft_push_stack(stack_from, stack_to);
		ft_print_stack(stack_to, "After push");
	}
	min_index = stack_min(stack_to);
	if (min_index < stack_to->size / 2)
		ft_reverse_rotate_n_times(stack_to, min_index + 1);
	else
		ft_rotate_n_times(stack_to, stack_to->top - min_index);
}
