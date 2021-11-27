/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:23 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/18 16:44:06 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_print_stack(t_stack *stack, char *message)
{
	int		i;

	i = stack->top;
	printf("-------------\n");
	printf("\n%s\n", message);
	printf("Stack %c\n", stack->identifier);
	printf("Size : %d\n", stack->size);
	printf("Top : %d\n", stack->top);
	while (i >= 0)
		printf("%d\n", stack->arr[i--]);
	printf("\n");
}
