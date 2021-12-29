/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:14:11 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/29 16:01:35 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdlib.h>

t_instruction_el	*create_instruction_el(char *instruction, char stack_identifier)
{
	t_instruction_el	*instruction_el;

	instruction_el = (t_instruction_el *)malloc(sizeof(t_instruction_el));
	instruction_el->instruction = ft_strdup(instruction);
	instruction_el->stack_identifier = stack_identifier;
	return (instruction_el);
}

void	destroy_instruction_el(void *instruction_input)
{
	t_instruction_el	*instruction_el;

	instruction_el = (t_instruction_el *)instruction_input;
	free(instruction_el->instruction);
	free(instruction_el);
}

void	print_instructions(void *instruction_input)
{
	t_instruction_el	*instruction_el;

	instruction_el = (t_instruction_el *)instruction_input;
	ft_printf("%s%c\n", instruction_el->instruction, instruction_el->stack_identifier);
}

int	optimise_instruction_for_double(t_list_el *instruction_el, char *instruction, char both_instructions)
{
	char				lookup_identifier;
	t_instruction_el	*instruction_el_content;
	t_instruction_el	*current_el_content;
	t_list_el			*current_el;
	t_list_el			*last_el;

	instruction_el_content = instruction_el->content;
	if (instruction_el_content->stack_identifier == 'a')
		lookup_identifier = 'b';
	else if (instruction_el_content->stack_identifier == 'b')
		lookup_identifier = 'a';
	else
		return (0);
	last_el = instruction_el;
	current_el = instruction_el->next;
	if (!current_el)
		return (0);
	current_el_content = current_el->content;
	while (current_el && current_el_content->stack_identifier != lookup_identifier)
	{
		if (ft_strcmp(current_el_content->instruction, "p") == 0)
			return (0);
		last_el = current_el;
		current_el = current_el->next;
		if (current_el)
			current_el_content = current_el->content;
	}
	if (ft_strcmp(current_el_content->instruction, "p") == 0)
		return (0);
	if (current_el && ft_strcmp(current_el_content->instruction, instruction) == 0 && current_el_content->stack_identifier != both_instructions)
	{
		instruction_el_content->stack_identifier = both_instructions;
		last_el->next = current_el->next;
		ft_lstdelone(current_el, destroy_instruction_el);
		return (1);
	}
	return (0);
}

int	optimise_instructions(t_list_el **lst)
{
	int					optimisations;
	t_list_el			*current_el;
	t_instruction_el	*current_instruction_el;

	current_el = *lst;
	optimisations= 0;
	while(current_el)
	{
		current_instruction_el = current_el->content;
		if (ft_strcmp(current_instruction_el->instruction, "r") == 0)
			optimisations += optimise_instruction_for_double(current_el, "r", 'r');
		else if (ft_strcmp(current_instruction_el->instruction, "rr") == 0)
			optimisations += optimise_instruction_for_double(current_el, "rr", 'r');
		else if (ft_strcmp(current_instruction_el->instruction, "s") == 0)
			optimisations += optimise_instruction_for_double(current_el, "s", 's');
		current_el = current_el->next;
	}
	return (optimisations);
}
