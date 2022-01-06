/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:23:35 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 16:23:54 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

int	get_next_number_to_insert(int *sorted_arr, int last_number)
{
	int		i;

	i = 0;
	while (sorted_arr[i] != last_number)
		i++;
	if (i == 0)
		return (sorted_arr[i]);
	else
		return (sorted_arr[i - 1]);
}

int	get_rotation_number_to_top(t_stack *stack, int number)
{
	int		number_index;
	int		rotations;
	int		reverse_rotations;

	number_index = get_number_index(stack, number);
	rotations = stack->top - number_index;
	reverse_rotations = stack->top - rotations + 1;
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (-reverse_rotations);
}
