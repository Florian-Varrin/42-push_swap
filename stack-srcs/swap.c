/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:54:42 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:41:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	swap_stack(t_stack *stack, _Bool print_operation)
{
	int		tmp;
	int		top;

	top = stack->top;
	tmp = stack->arr[top];
	stack->arr[top] = stack->arr[top - 1];
	stack->arr[top - 1] = tmp;
	if (print_operation)
		ft_printf("s%c\n", stack->identifier);
}

void	swap_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation)
{
	swap_stack(stack_a, false);
	swap_stack(stack_b, false);
	if (print_operation)
		ft_printf("ss\n");
}
