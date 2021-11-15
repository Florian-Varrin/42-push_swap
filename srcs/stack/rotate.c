/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:22:16 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:30:47 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rotate_stack(t_stack *stack)
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

void	ft_reverse_rotate_stack(t_stack *stack)
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
