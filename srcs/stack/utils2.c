/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:02:45 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 15:04:31 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>

_Bool	top_value_greater_bellow(t_stack *stack)
{
	if (stack_top_value(stack) > stack_value(stack, stack->top - 1))
		return (true);
	return (false);
}
