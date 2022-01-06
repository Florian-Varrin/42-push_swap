/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:09:59 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 12:10:18 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

t_stack	*reset_stack(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = stack->original_arr[i];
		i++;
	}
	return (stack);
}

t_stack	*destroy_stack(t_stack *stack)
{
	if (stack && stack->arr)
		free(stack->arr);
	if (stack && stack->sorted_arr)
		free(stack->sorted_arr);
	if (stack && stack->original_arr)
		free(stack->original_arr);
	if (stack)
		free(stack);
	return (NULL);
}
