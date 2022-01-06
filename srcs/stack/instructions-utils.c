/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions-utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:09:06 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 13:10:30 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdlib.h>
#include <stdbool.h>

_Bool	instruction_is_push(char *instruction)
{
	if (ft_strcmp(instruction, "p") == 0)
		return (true);
	return (false);
}

void	get_both_instruction_value(char *instruction, char *both_instructions)
{
	if (ft_strcmp(instruction, "r") == 0)
		*both_instructions = 'r';
	if (ft_strcmp(instruction, "rr") == 0)
		*both_instructions = 'r';
	if (ft_strcmp(instruction, "s") == 0)
		*both_instructions = 's';
}
