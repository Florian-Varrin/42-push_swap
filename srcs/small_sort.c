/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:20:33 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/24 17:23:24 by fvarrin          ###   ########.fr       */
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
