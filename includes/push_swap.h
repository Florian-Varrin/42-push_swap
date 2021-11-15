/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:59:33 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack {
	char	identifier;
	int		size;
	int		top;
	int		*arr;
}	t_stack;

// Init
t_stack		*ft_create_stack(int size, char identifier);
t_stack		*ft_destroy_stack(t_stack *stack);
t_stack		*ft_init_stack(int size, char **content, char identifier);
// Operations
void		ft_push_stack(t_stack *stack_from, t_stack *stack_to);
void		ft_swap_stack(t_stack *stack);
void		ft_swap_both_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate_stack(t_stack *stack);
void		ft_rotate_both_stack(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse_rotate_stack(t_stack *stack);
void		ft_reverse_rotate_both_stack(t_stack *stack_a, t_stack *stack_b);
// Debug
void		ft_print_stack(t_stack *stack);
#endif
