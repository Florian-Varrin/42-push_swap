/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:20:33 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 13:52:19 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "stack.h"

#include <stdbool.h>
#include <stdio.h>

void	sort_two(t_stack *stack, t_list_el **lst)
{
	if (stack->arr[0] > stack->arr[1])
		return ;
	else
		swap_stack(stack, lst);
}

void	sort_three(t_stack *stack, t_list_el **lst)
{
	int		max_index;

	max_index = stack_max_index(stack);
	if (stack_is_sorted(stack))
		return ;
	if (max_index == 2)
	{
		rotate_stack(stack, lst);
		sort_three(stack, lst);
	}
	else
	{
		swap_stack(stack, lst);
		sort_three(stack, lst);
	}
}

void	sort_until_five(t_stack *stack_a, t_stack *stack_b, t_list_el **lst)
{
	_Bool	need_to_sort_three;
	int		i;

	if (stack_is_sorted(stack_a) && stack_b->top < 0)
		return ;
	i = 0;
	need_to_sort_three = true;
	while ((i++) < stack_a->size - 3)
	{
		if (stack_is_ordered(stack_a))
		{
			need_to_sort_three = false;
			break ;
		}
		push_stack(stack_a, stack_b, lst);
	}
	if (need_to_sort_three)
		sort_three(stack_a, lst);
	instert_in_ordered_stack(stack_b, stack_a, lst);
}
