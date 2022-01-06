/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:38:51 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 13:11:36 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>

static char	_init_lookup_id(t_instruction_el *instruction_el_content)
{
	if (instruction_el_content->stack_identifier == 'a')
		return ('b');
	else if (instruction_el_content->stack_identifier == 'b')
		return ('a');
	return (0);
}

static _Bool	_init_vars(
		t_list_el *instruction_el,
		t_instruction_el **instruction_el_content,
		t_list_el **current_el,
		t_list_el **last_el
	)
{
	*instruction_el_content = instruction_el->content;
	*last_el = instruction_el;
	*current_el = instruction_el->next;
	if (!(*current_el))
		return (false);
	return (true);
}

static int	_do_optimisation(
		t_list_el *current_el,
		t_list_el *last_el,
		char *instruction,
		t_instruction_el *instruction_el_content
	)
{
	t_instruction_el	*current_el_content;
	char				both_instructions;

	get_both_instruction_value(instruction, &both_instructions);
	current_el_content = current_el->content;
	if (ft_strcmp(current_el_content->instruction, "p") == 0)
		return (0);
	if (current_el
		&& ft_strcmp(current_el_content->instruction, instruction) == 0
		&& current_el_content->stack_identifier != both_instructions)
	{
		instruction_el_content->stack_identifier = both_instructions;
		last_el->next = current_el->next;
		ft_lstdelone(current_el, destroy_instruction_el);
		return (1);
	}
	return (0);
}

int	optimise_instruction_for_double(
		t_list_el *instruction_el,
		char *instruction
	)
{
	char				lookup_id;
	t_instruction_el	*instruction_el_content;
	t_instruction_el	*current_el_content;
	t_list_el			*current_el;
	t_list_el			*last_el;

	if (!_init_vars(instruction_el, &instruction_el_content,
			&current_el, &last_el))
		return (0);
	lookup_id = _init_lookup_id(instruction_el_content);
	current_el_content = current_el->content;
	while (current_el && current_el_content->stack_identifier != lookup_id)
	{
		if (instruction_is_push(current_el_content->instruction))
			return (0);
		last_el = current_el;
		current_el = current_el->next;
		if (current_el)
			current_el_content = current_el->content;
	}
	return (_do_optimisation(current_el, last_el, instruction,
			instruction_el_content));
}

int	optimise_instructions(t_list_el **lst)
{
	int					optimisations;
	t_list_el			*current_el;
	t_instruction_el	*current_instruction_el;

	current_el = *lst;
	optimisations = 0;
	while (current_el)
	{
		current_instruction_el = current_el->content;
		if (ft_strcmp(current_instruction_el->instruction, "r") == 0)
			optimisations += optimise_instruction_for_double(current_el, "r");
		else if (ft_strcmp(current_instruction_el->instruction, "rr") == 0)
			optimisations += optimise_instruction_for_double(current_el, "rr");
		else if (ft_strcmp(current_instruction_el->instruction, "s") == 0)
			optimisations += optimise_instruction_for_double(current_el, "s");
		current_el = current_el->next;
	}
	return (optimisations);
}
