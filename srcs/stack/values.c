/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:56:09 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/08 13:32:50 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>

int	stack_top_value(t_stack *stack)
{
	if (stack->top < 0)
		return (-1);
	return (stack->arr[stack->top]);
}

int	stack_value(t_stack *stack, int index)
{
	if (index > stack->top)
		ft_printf("too big\n");
	if (index < 0)
		ft_printf("too small\n");
	return (stack->arr[index]);
}
