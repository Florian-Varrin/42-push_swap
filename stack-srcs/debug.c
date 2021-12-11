/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:23 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/11 16:28:43 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdio.h>

void	print_stack(t_stack *stack, char *message)
{
	int		i;

	i = stack->top;
	ft_printf("-------------\n");
	ft_printf("\n%s\n", message);
	ft_printf("Stack %c\n", stack->identifier);
	while (i >= 0)
		ft_printf("%d\n", stack->arr[i--]);
	printf("\n");
}
