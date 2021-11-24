/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:05:05 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/24 17:21:55 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>

_Bool	stack_is_sorted(t_stack *stack)
{
	int		i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->arr[i] > stack->arr[i - 1])
			return (false);
		i--;
	}
	return (true);
}

_Bool	stack_is_ordered(t_stack *stack)
{
	int		min_index;
	int		i;

	if (stack_is_sorted(stack))
		return (true);
	min_index = stack_min(stack);
	if (min_index != 0 && stack_max(stack) != min_index + 1)
		return (false);
	i = min_index;
	while (i != min_index + 1)
	{
		if (i == 0)
		{
			if (stack->arr[i] > stack->arr[stack->top])
				return (false);
			i = stack->top;
		}
		else
		{
			if (stack->arr[i] > stack->arr[i - 1])
				return (false);
			i--;
		}
	}
	return (true);
}

int	stack_max(t_stack *stack)
{
	int		i;
	int		max_index;

	i = 0;
	max_index = i;
	while (i <= stack->top)
	{
		if (stack->arr[i] > stack->arr[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	stack_min(t_stack *stack)
{
	int		i;
	int		min_index;

	i = 0;
	min_index = i;
	while (i <= stack->top)
	{
		if (stack->arr[i] < stack->arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
