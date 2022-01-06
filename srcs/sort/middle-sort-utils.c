/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle-sort-utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:55:48 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 15:57:58 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

void	select_pivot(t_stack *stack, int *max_pivot, int *min_pivot)
{
	int		min_value;
	int		max_value;

	max_value = stack_max_value(stack);
	min_value = stack_min_value(stack);
	*max_pivot = (max_value + min_value) / 2;
	*min_pivot = (*max_pivot + min_value) / 2;
}
