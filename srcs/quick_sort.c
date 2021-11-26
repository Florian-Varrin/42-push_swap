/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:00:02 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/24 18:18:41 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap_two_number(t_stack *stack_a, t_stack *stack_b, int bottom_index, int top_index)
{
	if (bottom_index + 1 < stack_a->top - top_index)
	{
		ft_reverse_rotate_n_times(stack_a, bottom_index);
		ft_push_stack(stack_a, stack_b);
		if (top_index + (bottom_index + 1) >= (stack_a->top + 1) / 2)
	}
	else
	{
		ft_rotate_n_times(stack_a, stack_a->top - top_index);
	}
}
