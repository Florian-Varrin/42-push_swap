/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:02:55 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 16:38:06 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

int	get_chunk_size(t_stack *stack, int chunk_number)
{
	return (stack->size / chunk_number);
}

void	separate_chunks_by_size(
			t_stack *stack_from,
			t_stack *stack_to,
			int chunk_infos[2],
			t_list_el **lst
		)
{
	int		rotations;
	int		reverse_rots;
	int		pushed;

	if (chunk_infos[0] > stack_from->size)
		return ;
	pushed = 0;
	while (pushed < chunk_infos[1])
	{
		rotations = -1;
		reverse_rots = -1;
		get_next_indexes(stack_from, chunk_infos, &rotations, &reverse_rots);
		if (rotations < 0 && reverse_rots < 0)
			continue ;
		rotations = stack_from->top - rotations;
		reverse_rots = reverse_rots + 1;
		if (rotations <= reverse_rots)
			rotate_n_times(stack_from, rotations, lst);
		else
			reverse_rotate_n_times(stack_from, reverse_rots, lst);
		push_stack(stack_from, stack_to, lst);
		pushed++;
	}
	chunk_infos[0] = chunk_infos[0] + chunk_infos[1];
	separate_chunks_by_size(stack_from, stack_to, chunk_infos, lst);
}

void	try_chunk_number(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el **lst,
			int chunk_number
		)
{
	int		i;
	int		chunk_infos[2];

	if (stack_is_sorted(stack_a))
		return ;
	chunk_infos[0] = 0;
	chunk_infos[1] = get_chunk_size(stack_a, chunk_number);
	separate_chunks_by_pivot(stack_a, stack_b, lst);
	i = 0;
	while (i < stack_a->size)
	{
		push_stack(stack_b, stack_a, lst);
		i++;
	}
	separate_chunks_by_size(stack_a, stack_b, chunk_infos, lst);
	instert_in_empty_stack(stack_b, stack_a, lst);
}

void	sort_after_four_hundred(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el **lst
		)
{
	t_list_el	*next_lst;
	int			i;
	int			best_instructions_count;
	int			current_instructions_count;
	int			best_chunk_number;

	best_instructions_count = -1;
	best_chunk_number = CHUNK_NUMBERS_START;
	i = CHUNK_NUMBERS_START - 1;
	while (++i <= CHUNK_NUMBERS_END)
	{
		next_lst = NULL;
		try_chunk_number(stack_a, stack_b, &next_lst, i + 1);
		optimise_instructions(&next_lst);
		current_instructions_count = count_instructions(next_lst);
		reset_stack(stack_a);
		if (i == CHUNK_NUMBERS_START
			|| current_instructions_count < best_instructions_count)
		{
			best_instructions_count = current_instructions_count;
			best_chunk_number = i + 1;
		}
		ft_lstclear(&next_lst, destroy_instruction_el);
	}
	try_chunk_number(stack_a, stack_b, lst, best_chunk_number);
}
