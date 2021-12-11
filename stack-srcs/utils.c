/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:05:05 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:28:55 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>

int	stack_max_index(t_stack *stack)
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

int	stack_max_value(t_stack *stack)
{
	int		max_index;

	max_index = stack_max_index(stack);
	return (stack->arr[max_index]);
}

int	stack_min_index(t_stack *stack)
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

int	stack_min_value(t_stack *stack)
{
	int		min_index;

	min_index = stack_min_index(stack);
	return (stack->arr[min_index]);
}
