/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:41:02 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/18 16:48:03 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

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
	ft_printf("executing %s\n", instruction);
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

_Bool	execute_instructions(t_state *state)
{
	t_list_el	*current_el;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = state->stack_a;
	stack_b = state->stack_b;
	if (!state->instructions_list)
		return (false);
	current_el = state->instructions_list;
	while (current_el)
	{
		usleep(state->speed);
		if (!state->is_playing)
			return (false);
		if (!execute_single_instruction(current_el->content, stack_a, stack_b))
		{
			ft_lstclear(&(state->instructions_list), &delete_instruction);
			exit_error(stack_a, stack_b);
		}
		current_el = current_el->next;
		ft_printf("Will render");
		render_image(state);
		ft_printf("Has render");
	}
	state->is_playing= (false);
	if (stack_is_sorted(stack_a) && stack_b->top == -1)
	{
		state->has_finished = true;
		return (true);
	}
	return (false);
}
