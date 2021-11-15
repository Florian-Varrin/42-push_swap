/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/09 18:14:21 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libft.h"
#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

t_stack	*ft_create_stack(int size, char identifier)
{
	t_stack		*stack;

	stack = (t_stack*)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (NULL);
	stack->identifier = identifier;
	stack->size = size;
	stack->top = -1;
	stack->arr = ft_calloc(sizeof(int), size);
	if (!stack->arr)
	{
		ft_destroy_stack(stack);
		return (NULL);
	}
	return (stack);
}

t_stack	*ft_push_stack(t_stack *stack, int n)
{
	if (stack->top == stack->size)
		return stack;
	stack->top++;
	stack->arr[stack->top] = n;
	return (stack);
}

t_stack	*ft_init_stack(int size, char **content, char identifier)
{
	int			i;
	int			n;
	t_stack		*stack;

	i = 0;
	stack = ft_create_stack(size, identifier);
	while (i < size)
	{
		n = ft_atoi(content[i]);
		ft_push_stack(stack, n);
	}
	return (stack);
}

t_stack	*ft_destroy_stack(t_stack *stack)
{
	if (stack->arr)
		free(stack->arr);
	if (stack)
		free(stack);
	return (NULL);
}

void	ft_printstack(t_stack *stack)
{
	int		i;

	i = stack->top;
	printf("Stack %c\n", stack->identifier);
	printf("Size : %d\n", stack->size);
	while (i >= 0)
		printf("%d\n", stack->arr[i--]);
}
