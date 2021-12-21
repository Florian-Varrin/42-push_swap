/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:58:17 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/21 13:49:09 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdbool.h>

void	rotate_ordered_to_be_sorted(t_stack *stack, t_list_el **lst)
{
	int		min_index;

	min_index = stack_min_index(stack);
	if (min_index < stack->size / 2)
		reverse_rotate_n_times(stack, min_index + 1, lst);
	else
		rotate_n_times(stack, stack->top - min_index, lst);
}
