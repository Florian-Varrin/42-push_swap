/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:05:05 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 15:24:27 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>

_Bool	stack_is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	stack_max(t_stack *stack)
{
	int		i;
	int		max_index;

	i = 0;
	max_index = i;
	while (i <= stack->top) {
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
	while (i <= stack->top) {
		if (stack->arr[i] < stack->arr[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
