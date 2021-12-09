/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:58:17 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 14:14:21 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_rotate_ordered_to_be_sorted(t_stack *stack)
{
	int		min_index;

	min_index = stack_min_index(stack);
	if (min_index < stack->size / 2)
		ft_reverse_rotate_n_times(stack, min_index + 1);
	else
		ft_rotate_n_times(stack, stack->top - min_index);
}
