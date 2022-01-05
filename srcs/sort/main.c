/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:31:19 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/05 17:48:21 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdio.h>
#include <stdbool.h>

void	destroy_all_and_exit(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el *instructions_list
		)
{
	ft_lstclear(&instructions_list, destroy_instruction_el);
	destroy_stack(stack_a);
	stack_b->sorted_arr = NULL;
	destroy_stack(stack_b);
}

int	main(int argc, char **argv)
{
	int			optimisations;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list_el	*instructions_list;

	instructions_list = NULL;
	if (argc == 1)
		exit_error(NULL, NULL);
	parse_arg(&stack_a, &stack_b, argc - 1, &argv[1]);
	if (stack_a->size == 3)
		sort_two(stack_a, &instructions_list);
	else if (stack_a->size == 3)
		sort_three(stack_a, &instructions_list);
	else if (stack_a->size >= 4 && stack_a->size <= 5)
		sort_until_five(stack_a, stack_b, &instructions_list);
	else if (stack_a->size > 5 && stack_a->size <= 400)
		sort_until_four_hundred(stack_a, stack_b, &instructions_list);
	else
		sort_after_four_hundred(stack_a, stack_b, &instructions_list);
	optimisations = -1;
	while (optimisations != 0)
		optimisations = optimise_instructions(&instructions_list);
	/* ft_lstiter(instructions_list, print_instructions); */
	destroy_all_and_exit(stack_a, stack_b, instructions_list);
	return (0);
}
