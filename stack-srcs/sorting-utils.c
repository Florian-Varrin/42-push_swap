/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:37:27 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:29:04 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

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

_Bool	partition_is_sorted(t_stack *stack, int start, int end)
{
	int		i;
	int		number_of_checks;

	if (start == end)
		return (true);
	if (start > end)
		number_of_checks = start - end + 1;
	else
		number_of_checks = end - start;
	i = end;
	while (number_of_checks > 0)
	{
		if (stack->arr[i] > stack->arr[i - 1])
			return (false);
		i--;
		number_of_checks--;
	}
	return (true);
}

_Bool	stack_is_ordered(t_stack *stack)
{
	int		min_index;
	int		i;

	if (stack_is_sorted(stack))
		return (true);
	min_index = stack_min_index(stack);
	if (min_index != 0 && stack_max_index(stack) != min_index + 1)
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
