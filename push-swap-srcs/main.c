/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:31:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/16 09:42:01 by fvarrin          ###   ########.fr       */
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

	if (argc == 1)
		exit_error(NULL, NULL);
	parse_arg(&stack_a, &stack_b, argc - 1, &argv[1]);
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size >= 4 && stack_a->size <= 5)
		sort_until_five(stack_a, stack_b);
	else
		sort_until_hundred(stack_a, stack_b);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return (0);
}