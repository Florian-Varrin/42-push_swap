/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:20:33 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 15:32:02 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_sort_two(t_stack *stack)
{
	if (stack->arr[0] < stack->arr[1])
		return ;
	else
		ft_swap_stack(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int		min;

	min = stack_min(stack);
	if (stack_is_sorted(stack))
		return ;
	if (min == 2)
	{
		ft_rotate_stack(stack);
		ft_sort_three(stack);
	}
	else
	{
		ft_swap_stack(stack);
		ft_sort_three(stack);
	}
}
