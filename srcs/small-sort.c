/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:20:33 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 14:14:30 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>
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
	int		max_index;

	max_index = stack_max_index(stack);
	if (stack_is_sorted(stack))
		return ;
	if (max_index == 2)
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

void	ft_sort_until_five(t_stack *stack_a, t_stack *stack_b)
{
	_Bool	sort_three;
	int		i;

	if (stack_is_sorted(stack_a) && stack_b->top < 0)
		return ;
	i = 0;
	sort_three = true;
	while ((i++) < stack_a->size - 3)
	{
		if (stack_is_ordered(stack_a))
		{
			sort_three = false;
			break ;
		}
		ft_push_stack(stack_a, stack_b);
	}
	if (sort_three)
		ft_sort_three(stack_a);
	ft_instert_in_ordered_stack(stack_b, stack_a);
}

void	ft_sort_until_ten(t_stack *stack_a, t_stack *stack_b)
{
	_Bool	sort_five;
	int		min_index;

	sort_five = true;
	while (stack_a->top >= 4)
	{
		min_index = stack_min_index(stack_a);
		if (stack_is_ordered(stack_a))
		{
			sort_five = false;
			break ;
		}
		if (min_index > (stack_a->top + 1) / 2)
			ft_rotate_n_times(stack_a, stack_a->top - min_index);
		else
			ft_reverse_rotate_n_times(stack_a, min_index + 1);
		ft_push_stack(stack_a, stack_b);
	}
	if (sort_five)
		ft_sort_until_five(stack_a, stack_b);
	ft_instert_in_ordered_stack(stack_b, stack_a);
}
