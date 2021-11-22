/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:31:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/22 13:19:52 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = ft_init_stack(argc - 1, &argv[1], 'a');
	stack_b = ft_create_stack(argc - 1, 'b');
	ft_print_stack(stack_a, "Init");
	if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size >= 4 && stack_a->size <= 5)
		ft_sort_until_five(stack_a, stack_b);
	ft_print_stack(stack_a, "End");
	ft_destroy_stack(stack_a);
	ft_destroy_stack(stack_b);
	return (0);
}
