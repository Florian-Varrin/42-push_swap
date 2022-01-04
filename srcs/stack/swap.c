/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:54:42 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 14:58:12 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	swap_stack(t_stack *stack, t_list_el **lst)
{
	int			tmp;
	int			top;
	t_list_el	*el;

	if (stack->top <= 0)
		return ;
	top = stack->top;
	tmp = stack->arr[top];
	stack->arr[top] = stack->arr[top - 1];
	stack->arr[top - 1] = tmp;
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("s", stack->identifier));
		ft_lstadd_back(lst, el);
	}
}

void	swap_both_stack(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el **lst
		)
{
	t_list_el	*el;

	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("s", 's'));
		ft_lstadd_back(lst, el);
	}
}
