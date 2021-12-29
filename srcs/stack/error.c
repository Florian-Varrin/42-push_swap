/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:06:28 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 15:06:11 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdlib.h>

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		destroy_stack(stack_a);
	if (stack_b)
		destroy_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
