/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:23 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/01 17:04:34 by fvarrin          ###   ########.fr       */
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
	while (i >= 0)
		printf("%d\n", stack->arr[i--]);
	printf("\n");
}
