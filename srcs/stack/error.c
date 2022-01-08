/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:06:28 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/08 13:05:01 by fvarrin          ###   ########.fr       */
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
	ft_perror("Error\n");
	exit(-1);
}
