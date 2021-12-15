/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:00:12 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 14:50:20 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"

#include <fcntl.h>

void	print_instructions(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int	main(int argc, char **argv)
{
	t_list_el	*instructions_list;
	t_stack		*stack_a;
	t_stack		*stack_b;
	
	if (argc <= 1)
		return (-1);
	instructions_list = parse_instructions();
	if (!instructions_list)
		error(NULL, NULL);
	parse_arg(&stack_a, &stack_b, argc, argv);
	if (execute_instructions(instructions_list, stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	ft_lstclear(&instructions_list, &delete_instruction);
	return (0);
}
