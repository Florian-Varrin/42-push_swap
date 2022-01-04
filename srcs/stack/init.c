/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/29 16:33:32 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

t_stack	*create_stack(int size, char identifier)
{
	t_stack		*stack;

	stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (NULL);
	stack->identifier = identifier;
	stack->size = size;
	stack->top = -1;
	stack->arr = ft_calloc(sizeof(int), size);
	stack->sorted_arr = ft_calloc(sizeof(int), size);
	if (!stack->arr)
	{
		destroy_stack(stack);
		return (NULL);
	}
	return (stack);
}

t_stack	*sort_stack_arr(t_stack *stack)
{
	int		i;
	int		swapped;

	i = 0;
	while (i < stack->size) {
		stack->sorted_arr[i] = stack->arr[i];
		i++;
	}
	swapped = -1;
	while (swapped != 0)
	{
		i = 0;
		swapped = 0;
		while (i < (stack->size - 1))
		{
			if (stack->sorted_arr[i] > stack->sorted_arr[i + 1])
			{
				ft_swap(&(stack->sorted_arr[i]), &(stack->sorted_arr[i + 1]));
				swapped++;
			}
			i++;
		}
	}
	return (stack);
}

t_stack	*fill_stack(t_stack *stack, int n)
{
	int		i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->arr[i] == n)
			exit_error(stack, NULL);
		i++;
	}
	if (stack->top == stack->size)
		return (stack);
	stack->top++;
	stack->arr[stack->top] = n;
	sort_stack_arr(stack);
	return (stack);
}

t_stack	*init_stack(int size, char **content, char identifier)
{
	int			i;
	int			n;
	t_stack		*stack;

	i = size - 1;
	stack = create_stack(size, identifier);
	while (i >= 0)
	{
		n = ft_atoi(content[i--]);
		fill_stack(stack, n);
	}
	return (stack);
}

t_stack	*destroy_stack(t_stack *stack)
{
	if (stack && stack->arr)
		free(stack->arr);
	if (stack && stack->sorted_arr)
		free(stack->sorted_arr);
	if (stack)
		free(stack);
	return (NULL);
}
