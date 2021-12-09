/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:31:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/09 17:05:54 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	ft_parse_arg(&stack_a, &stack_b, argc, argv);
	ft_push_stack(stack_a, stack_b);
	#if DEBUG == 1
		ft_print_stack(stack_a, "Init");
	#endif
	/* if (stack_a->size == 2) */
	/* 	ft_sort_two(stack_a); */
	/* else if (stack_a->size == 3) */
	/* 	ft_sort_three(stack_a); */
	/* else if (stack_a->size >= 4 && stack_a->size <= 5) */
	/* 	ft_sort_until_five(stack_a, stack_b); */
	/* else if (stack_a->size > 5 && stack_a->size <= 10) */
	/* 	ft_sort_until_ten(stack_a, stack_b); */
	/* else */
	/* ft_sort_until_hundred(stack_a, stack_b); */

	ft_instert_in_ordered_stack(stack_b, stack_a);
	#if DEBUG == 1
		ft_print_stack(stack_a, "End");
	#endif
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
	return (0);
}
