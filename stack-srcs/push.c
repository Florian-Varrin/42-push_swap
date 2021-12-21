/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:15 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/21 13:28:59 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void	push_stack(
			t_stack *stack_from,
			t_stack *stack_to,
			t_list_el **lst
		)
{
	t_list_el	*el;

	if (stack_from->top == -1)
		return ;
	stack_to->arr[++stack_to->top] = stack_from->arr[stack_from->top--];
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("p", stack_to->identifier));
		ft_lstadd_back(lst, el);
	}
}
