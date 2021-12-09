/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:14:02 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 15:55:30 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

_Bool	ft_check_args(char **args, int *size)
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
				return (false);
			j++;
		}
		i++;
	}
	*size = i;
	return (true);
}

char	**ft_parse_single_arg(char *str, char **args, int *size)
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
	if (!ft_check_args(args, size))
	{
		free(args);
		ft_error(NULL, NULL);
	}
	return (args);
}

char	**ft_parse_multiple_arg(char **argv, int argc, char **args, int *size)
{
	int		i;

	args = (char **)ft_calloc(sizeof(char *), argc);
	i = 0;
	while (i < argc)
	{
		args[i] = argv[i];
		i++;
	}
	if (!ft_check_args(args, size))
	{
		free(args);
		ft_error(NULL, NULL);
	}
	return (args);
}

void	ft_parse_arg(t_stack **stack_a, t_stack **stack_b,
			int argc, char **argv)
{
	char	**args;
	int		size;

	if (argc == 1)
		ft_error(NULL, NULL);
	args = NULL;
	if (argc == 2)
		args = ft_parse_single_arg(argv[1], args, &size);
	else
		args = ft_parse_multiple_arg(&argv[1], argc, args, &size);
	*stack_a = ft_init_stack(size, args, 'a');
	*stack_b = ft_create_stack(size, 'b');
	free(args);
}
