/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:54:42 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:18:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap_stack(t_stack *stack)
{
	int		tmp;
	int		top;

	top = stack->top;
	tmp = stack->arr[top];
	stack->arr[top] = stack->arr[top - 1];
	stack->arr[top - 1] = tmp;
}
