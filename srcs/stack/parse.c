/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:14:02 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/05 17:52:23 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

_Bool	check_args(char **args, int *size)
{
	int		i;
	int		j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (!(args[i][j] == '-' && ft_strcmp(args[i], "-")))
					return (false);
			}
			j++;
		}
		i++;
	}
	*size = i;
	return (true);
}

char	**parse_single_arg(char *str, char **args, int *size)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
	args = ft_split(str, ' ');
	if (!check_args(args, size))
	{
		free(args);
		exit_error(NULL, NULL);
	}
	return (args);
}

char	**parse_multiple_arg(
			char **argv,
			int args_number,
			char **args,
			int *size
		)
{
	int		i;

	args = (char **)ft_calloc(sizeof(char *), args_number + 1);
	i = 0;
	while (i < args_number + 1)
	{
		args[i] = argv[i];
		i++;
	}
	if (!check_args(args, size))
	{
		free(args);
		exit_error(NULL, NULL);
	}
	return (args);
}

void	parse_arg(
			t_stack **stack_a,
			t_stack **stack_b,
			int args_number,
			char **first_arg
		)
{
	char	**args;
	int		size;

	size = 0;
	args = NULL;
	if (args_number == 1)
		args = parse_single_arg(first_arg[0], args, &size);
	else
		args = parse_multiple_arg(&first_arg[0], args_number, args, &size);
	*stack_a = init_stack(size, args, 'a');
	*stack_b = create_stack(size, 'b');
	free((*stack_b)->sorted_arr);
	(*stack_b)->sorted_arr = (*stack_a)->sorted_arr;
	free(args);
}
