/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:18:06 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>


t_stack	*ft_push_stack(t_stack *stack, int n)
{
	if (stack->top == stack->size)
		return (stack);
	stack->top++;
	stack->arr[stack->top] = n;
	return (stack);
}
