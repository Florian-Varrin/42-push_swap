/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort-utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:03:18 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/08 13:35:32 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

static void	_set_bottom_number_index(
			t_stack *stack_from,
			int chunk_infos[2],
			int *i,
			int *bottom_number_index
		)
{
	int		j;

	j = chunk_infos[0];
	while (j < chunk_infos[0] + chunk_infos[1])
	{
		if (*i < 0 || *i > stack_from->top)
		{
			*bottom_number_index = 0;
			break ;
		}
		if (stack_value(stack_from, *i) == stack_from->sorted_arr[j])
		{
			*bottom_number_index = *i;
			break ;
		}
		j++;
	}
	(*i)++;
}

static void	_set_top_number_index(
			t_stack *stack_from,
			int chunk_infos[2],
			int *i,
			int *top_number_index
		)
{
	int		j;

	j = chunk_infos[0];
	while (j < chunk_infos[0] + chunk_infos[1])
	{
		if (*i < 0 || *i > stack_from->top)
		{
			*top_number_index = 0;
			break ;
		}
		if (stack_value(stack_from, *i) == stack_from->sorted_arr[j])
		{
			*top_number_index = *i;
			break ;
		}
		j++;
	}
	(*i)--;
}

void	get_next_indexes(
			t_stack *stack_from,
			int chunk_infos[2],
			int *top_number_index,
			int *bottom_number_index
		)
{
	int		i;

	i = stack_from->top;
	while (*top_number_index == -1)
		_set_top_number_index(stack_from, chunk_infos, &i, top_number_index);
	i = 0;
	while (*bottom_number_index == -1)
		_set_bottom_number_index(stack_from, chunk_infos,
			&i, bottom_number_index);
}
