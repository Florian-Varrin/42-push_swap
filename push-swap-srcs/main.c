/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:31:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/21 15:03:21 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list_el	*instructions_list;

	instructions_list = NULL;
	if (argc == 1)
		exit_error(NULL, NULL);
	parse_arg(&stack_a, &stack_b, argc - 1, &argv[1]);
	if (stack_a->size == 2)
		sort_two(stack_a, &instructions_list);
	else if (stack_a->size == 3)
		sort_three(stack_a, &instructions_list);
	else if (stack_a->size >= 4 && stack_a->size <= 5)
		sort_until_five(stack_a, stack_b, &instructions_list);
	else
		sort_until_hundred(stack_a, stack_b, &instructions_list);
	/* optimise_instructions(&instructions_list); */
	ft_lstiter(instructions_list, print_instructions);
	/* print_stack(stack_a, "Test"); */
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return (0);
}
