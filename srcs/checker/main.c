/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:42:51 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 17:13:13 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"
#include "checker.h"

#include <stdio.h>
#include <stdbool.h>

void	destroy_all_and_exit(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el *instructions_list
		)
{
	ft_lstclear(&instructions_list, delete_instruction);
	destroy_stack(stack_a);
	stack_b->sorted_arr = NULL;
	destroy_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list_el	*instructions_list;
	_Bool		result;

	instructions_list = NULL;
	if (argc == 1)
		exit_error(NULL, NULL);
	parse_instructions(&instructions_list);
	if (!instructions_list)
		exit_error(NULL, NULL);
	parse_arg(&stack_a, &stack_b, argc - 1, &argv[1]);
	result = execute_instructions(stack_a, stack_b, instructions_list);
	if (result)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
