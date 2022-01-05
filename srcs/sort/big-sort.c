/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big-sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:02:55 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/05 17:47:26 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	get_next_indexes(t_stack *stack_from, int chunk_start, int *top_number_index, int *bottom_number_index, int chunk_size)
{
	int		i;
	int		j;

	i = stack_from->top;
	j = chunk_start;
	while (*top_number_index == -1)
	{
		while (j < chunk_start + chunk_size)
		{
			if (i < 0 || j < 0)
			{
				*top_number_index = i;
				break ;
			}
			if (stack_from->arr[i] == stack_from->sorted_arr[j])
			{
				*top_number_index = i;
				break ;
			}
			j++;
		}
		i--;
		j = chunk_start;
	}
	i = 0;
	j = chunk_start;
	while (*bottom_number_index == -1)
	{
		while (j < chunk_start + chunk_size)
		{
			if (i <= 0 || j < 0)
			{
				*bottom_number_index = i;
				break ;
			}
			ft_printf("i %d\n", i);
			if (stack_from->arr[i] == stack_from->sorted_arr[j])
			{
				*bottom_number_index = i;
				break ;
			}
			j++;
		}
		i++;
		j = chunk_start;
	}
}

int	get_chunk_size(t_stack *stack, int chunk_number)
{
	if (stack->size % chunk_number == 0)
		return (stack->size / chunk_number);
	return (stack->size / chunk_number + 1);
}


void	separate_chunks_by_size(t_stack *stack_from, t_stack *stack_to, int chunk_start, int chunk_size, t_list_el **lst)
{
	int		rotations;
	int		reverse_rotations;
	int		pushed;

	if (chunk_start > stack_from->size)
		return ;
	pushed = 0;
	while (pushed < chunk_size)
	{
		rotations = -1;
		reverse_rotations = -1;
		get_next_indexes(stack_from, chunk_start, &rotations, &reverse_rotations, chunk_size);
		if (rotations < 0 && reverse_rotations < 0)
			continue ;
		rotations = stack_from->top - rotations;
		reverse_rotations = reverse_rotations + 1;
		if (rotations <= reverse_rotations)
			rotate_n_times(stack_from, rotations, lst);
		else
			reverse_rotate_n_times(stack_from, reverse_rotations, lst);
		push_stack(stack_from, stack_to, lst);
		pushed++;
	}
	separate_chunks_by_size(stack_from, stack_to, chunk_start + chunk_size, chunk_size, lst);
}

void	try_chunk_number(t_stack *stack_a, t_stack *stack_b, t_list_el **lst, int chunk_number)
{
	int		i;
	int		chunk_size;

	if (stack_is_sorted(stack_a))
		return ;
	chunk_size = get_chunk_size(stack_a, chunk_number);
	separate_chunks_by_pivot(stack_a, stack_b, lst);
	i = 0;
	while (i < stack_a->size)
	{
		push_stack(stack_b, stack_a, lst);
		i++;
	}
	separate_chunks_by_size(stack_a, stack_b, 0, chunk_size, lst);
	instert_in_empty_stack(stack_b, stack_a, lst);
}

void	sort_after_four_hundred(t_stack *stack_a, t_stack *stack_b, t_list_el **lst)
{
	t_list_el	*next_lst;
	int			i;
	int			best_instructions_count;
	int			current_instructions_count;

	i = 0;
	while (i < CHUNK_NUMBERS)
	{
		next_lst = NULL;
		try_chunk_number(stack_a, stack_b, &next_lst, i + 1);
		optimise_instructions(&next_lst);
		current_instructions_count = count_instructions(next_lst);
		/* ft_printf("current_instructions_count %d\n", current_instructions_count); */
		reset_stack(stack_a);
		if (i == 0 || current_instructions_count < best_instructions_count)
		{
			if (current_instructions_count != 0)
			{
				ft_lstclear(lst, destroy_instruction_el);
				*lst = NULL;
				best_instructions_count = current_instructions_count;
				try_chunk_number(stack_a, stack_b, lst, i + 1);
			}
		}
		ft_lstclear(&next_lst, destroy_instruction_el);
		i++;
		current_instructions_count = 0;
	}
}
