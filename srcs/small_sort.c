/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:20:33 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 16:17:29 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_sort_two(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
		return ;
	else
		ft_swap_stack(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int		max;

	max = stack_max(stack);
	if (stack_is_sorted(stack))
		return ;
	if (max == 2)
	{
		ft_rotate_stack(stack);
		ft_sort_three(stack);
	}
	else
	{
		ft_swap_stack(stack);
		ft_sort_three(stack);
	}
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int		min;

	if (stack_is_sorted(stack_a) && stack_b->top >= 0)
		return ;
	min = stack_min(stack_a);
	ft_rotate_n_times(stack_a, (3 - min));
	ft_push_stack(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_push_stack(stack_b, stack_a);
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		min;

	if (stack_is_sorted(stack_a))
		return ;
	min = stack_min(stack_a);
	ft_rotate_n_times(stack_a, (4 - min));
	ft_push_stack(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_push_stack(stack_b, stack_a);
}
