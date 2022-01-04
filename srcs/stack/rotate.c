/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:22:16 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 14:57:32 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	rotate_stack(t_stack *stack, t_list_el **lst)
{
	int			i;
	int			tmp;
	t_list_el	*el;

	if (stack->top <= 0)
		return ;
	i = stack->top;
	tmp = stack->arr[i];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = tmp;
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("r", stack->identifier));
		ft_lstadd_back(lst, el);
	}
}

void	rotate_both_stack(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el **lst
		)
{
	t_list_el	*el;

	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("r", 'r'));
		ft_lstadd_back(lst, el);
	}
}

void	rotate_n_times(t_stack *stack, int n, t_list_el **lst)
{
	int		i;

	i = 0;
	while (i < n)
	{
		rotate_stack(stack, lst);
		i++;
	}
}
