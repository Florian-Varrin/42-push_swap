/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:54:42 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 16:10:01 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libft.h"
#include "push_swap.h"

void	_swaper(t_stack *stack)
{
	int		tmp;
	int		top;

	top = stack->top;
	tmp = stack->arr[top];
	stack->arr[top] = stack->arr[top - 1];
	stack->arr[top - 1] = tmp;
}

void	ft_swap_stack(t_stack *stack)
{
	_swaper(stack);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack->identifier, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_swap_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	_swaper(stack_a);
	_swaper(stack_b);
	ft_putstr_fd("ss\n", 1);
}
