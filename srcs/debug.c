/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:23 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:01:26 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	int		i;

	i = stack->top;
	printf("Stack %c\n", stack->identifier);
	printf("Size : %d\n", stack->size);
	while (i >= 0)
		printf("%d\n", stack->arr[i--]);
}
