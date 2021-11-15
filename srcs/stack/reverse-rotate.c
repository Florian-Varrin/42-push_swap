/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:10 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:56:47 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	_reverse_roter(t_stack *stack)
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
}

void	ft_reverse_rotate_stack(t_stack *stack)
{
	_reverse_roter(stack);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->identifier, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	_reverse_roter(stack_a);
	_reverse_roter(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
