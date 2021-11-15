/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:22:16 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 16:06:36 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	_roter(t_stack *stack)
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
}

void	ft_rotate_stack(t_stack *stack)
{
	_roter(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack->identifier, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	_roter(stack_a);
	_roter(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	ft_rotate_n_times(t_stack *stack, int n)
{
	int		i;

	i = 0;
	while (i < n) {
		ft_rotate_stack(stack);
		i++;
	}
}
