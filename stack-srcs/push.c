/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:46:32 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void	push_stack(t_stack *stack_from, t_stack *stack_to, _Bool print_operation)
{
	if (stack_from->top == -1)
		return ;
	stack_to->arr[++stack_to->top] = stack_from->arr[stack_from->top--];
	if (print_operation)
		ft_printf("p%c\n", stack_to->identifier);
}
