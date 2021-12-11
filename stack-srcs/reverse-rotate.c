/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:10 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:38:35 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	reverse_rotate_stack(t_stack *stack, _Bool print_operation)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = stack->arr[i];
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
	if (print_operation)
		ft_printf("rr%c\n", stack->identifier);
}

void	reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b, _Bool print_operation)
{
	reverse_rotate_stack(stack_a, false);
	reverse_rotate_stack(stack_b, false);
	if (print_operation)
		ft_printf("rrr\n");
}

void	reverse_rotate_n_times(t_stack *stack, int n, _Bool print_operation)
{
	int		i;

	i = 0;
	while (i < n)
	{
		reverse_rotate_stack(stack, print_operation);
		i++;
	}
}
