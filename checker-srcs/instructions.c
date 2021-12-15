/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:41:02 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 15:19:28 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"

#include <stdbool.h>
#include <stdlib.h>

void	delete_instruction(void	*instruction)
{
	if (instruction)
		free(instruction);
}

t_list_el	*add_instruction(t_list_el *instructions_list, char *instruction)
{
	t_list_el	*instruction_el;

	instruction_el = ft_lstnew(ft_strdup(ft_strtrim(instruction, "\n")));
	if (!instruction_el)
	{
		ft_lstclear(&instructions_list, &delete_instruction);
		return (NULL);
	}
	ft_lstadd_back(&instructions_list, instruction_el);
	return (instructions_list);
}

t_list_el	*parse_instructions(void)
{
	char		*str;
	t_list_el	*instructions_list;

	instructions_list = NULL;
	str = ft_get_next_line(0);
	while (str)
	{
		instructions_list = add_instruction(instructions_list, str);
		if (!instructions_list)
			return (NULL);
		str = ft_get_next_line(0);
	}
	return (instructions_list);
}

_Bool	execute_single_instruction(
			char *instruction,
			t_stack *stack_a,
			t_stack *stack_b
		)
{
	if (ft_strcmp(instruction, "sa") == 0)
		swap_stack(stack_a, false);
	else if (ft_strcmp(instruction, "sb") == 0)
		swap_stack(stack_b, false);
	else if (ft_strcmp(instruction, "ss") == 0)
		swap_both_stack(stack_a, stack_b, false);
	else if (ft_strcmp(instruction, "pa") == 0)
		push_stack(stack_b, stack_a, false);
	else if (ft_strcmp(instruction, "pb") == 0)
		push_stack(stack_a, stack_b, false);
	else if (ft_strcmp(instruction, "ra") == 0)
		rotate_stack(stack_a, false);
	else if (ft_strcmp(instruction, "rb") == 0)
		rotate_stack(stack_b, false);
	else if (ft_strcmp(instruction, "rr") == 0)
		rotate_both_stack(stack_a, stack_b, false);
	else if (ft_strcmp(instruction, "rra") == 0)
		reverse_rotate_stack(stack_a, false);
	else if (ft_strcmp(instruction, "rrb") == 0)
		reverse_rotate_stack(stack_b, false);
	else if (ft_strcmp(instruction, "rrr") == 0)
		reverse_rotate_both_stack(stack_a, stack_b, false);
	else
		return (false);
	return (true);
}

_Bool	execute_instructions(
			t_list_el *instructions_list,
			t_stack *stack_a,
			t_stack *stack_b
		)
{
	t_list_el	*current_el;

	if (!instructions_list)
		return (false);
	current_el = instructions_list;
	while (current_el)
	{
		if (!execute_single_instruction(current_el->content, stack_a, stack_b))
		{
			ft_lstclear(&instructions_list, &delete_instruction);
			exit_error(stack_a, stack_b);
		}
		current_el = current_el->next;
	}
	if (stack_is_sorted(stack_a) && stack_b->top == -1)
		return (true);
	return (false);
}
