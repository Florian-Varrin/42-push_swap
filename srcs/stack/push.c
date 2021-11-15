/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:50:23 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libft.h"
#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

void	ft_push_stack(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top == -1)
		return ;
	stack_to->arr[++stack_to->top] = stack_from->arr[stack_from->top--];
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack_to->identifier, 1);
	ft_putchar_fd('\n', 1);
}
