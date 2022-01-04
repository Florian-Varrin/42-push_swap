/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse-rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:10 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/04 14:57:46 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

#include <stdbool.h>

void	reverse_rotate_stack(t_stack *stack, t_list_el **lst)
{
	int			i;
	int			tmp;
	t_list_el	*el;

	if (stack->top <= 0)
		return ;
	i = 0;
	tmp = stack->arr[i];
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("rr", stack->identifier));
		ft_lstadd_back(lst, el);
	}
}

void	reverse_rotate_both_stack(
			t_stack *stack_a,
			t_stack *stack_b,
			t_list_el **lst
		)
{
	t_list_el	*el;

	reverse_rotate_stack(stack_a, NULL);
	reverse_rotate_stack(stack_b, NULL);
	if (lst)
	{
		el = ft_lstnew(create_instruction_el("rr", 'r'));
		ft_lstadd_back(lst, el);
	}
}

void	reverse_rotate_n_times(t_stack *stack, int n, t_list_el **lst)
{
	int		i;

	i = 0;
	while (i < n)
	{
		reverse_rotate_stack(stack, lst);
		i++;
	}
}
