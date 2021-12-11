/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:22:16 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:40:27 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	rotate_stack(t_stack *stack, _Bool print_operation)
{
	int		i;
	int		tmp;

	i = stack->top;
	tmp = stack->arr[i];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = tmp;
	if (print_operation)
		ft_printf("r%c\n", stack->identifier);
}

void	rotate_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation)
{
	rotate_stack(stack_a, false);
	rotate_stack(stack_b, false);
	if (print_operation)
		ft_printf("rr\n");
}

void	rotate_n_times(t_stack *stack, int n, _Bool print_operation)
{
	int		i;

	i = 0;
	while (i < n)
	{
		rotate_stack(stack, print_operation);
		i++;
	}
}
