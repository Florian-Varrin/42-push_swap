/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:14:11 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 13:50:29 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>

t_instruction_el	*create_instruction_el(
		char *instruction,
		char stack_identifier
	)
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
	char				*instruction;
	char				stack_identifier;

	instruction_el = (t_instruction_el *)instruction_input;
	instruction = instruction_el->instruction;
	stack_identifier = instruction_el->stack_identifier;
	ft_printf("%s%c\n", instruction, stack_identifier);
}

int	count_instructions(t_list_el *lst)
{
	t_list_el	*current_el;
	int			count;

	count = 0;
	if (!lst)
		return (0);
	current_el = lst;
	while (current_el)
	{
		count++;
		current_el = current_el->next;
	}
	return (count);
}
