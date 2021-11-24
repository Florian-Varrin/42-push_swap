/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:44:54 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/24 17:23:00 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

int	ft_get_last_index(t_stack *stack, int rotation)
{
	if (rotation == 0)
		return (0);
	return (stack->top - rotation + 1);
}

int	ft_get_rotation_number_to_insert(t_stack *stack, int number_to_insert)
{
	int		i_rotate;
	int		i_reverse;

	if (number_to_insert < stack->arr[stack_min(stack)])
		return (stack->top - stack_min(stack));
	if (number_to_insert > stack->arr[stack_max(stack)])
		return (-stack_max(stack));
	i_rotate = 0;
	while (!(stack->arr[stack->top - i_rotate] > number_to_insert
			&& stack->arr[ft_get_last_index(stack, i_rotate)]
			< number_to_insert))
		i_rotate++;
	i_reverse = stack->top + 1 - i_rotate;
	if (i_rotate < i_reverse)
		return (i_rotate);
	return (-i_reverse);
}

void	ft_instert_in_ordered_stack(t_stack *stack_from, t_stack *stack_to)
{
	int		number_to_insert;
	int		rotation;
	int		min_index;

	while (stack_from->top != -1)
	{
		number_to_insert = stack_from->arr[stack_from->top];
		rotation = ft_get_rotation_number_to_insert(stack_to, number_to_insert);
		if (rotation >= 0)
			ft_rotate_n_times(stack_to, rotation);
		else
			ft_reverse_rotate_n_times(stack_to, -rotation);
		ft_push_stack(stack_from, stack_to);
	}
	min_index = stack_min(stack_to);
	if (min_index < stack_to->size / 2)
		ft_reverse_rotate_n_times(stack_to, min_index + 1);
	else
		ft_rotate_n_times(stack_to, stack_to->top - min_index);
}
