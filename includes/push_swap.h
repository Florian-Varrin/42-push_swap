/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:19 by fvarrin           #+#    #+#             */
/*   Updated: 2021/11/15 14:41:28 by fvarrin          ###   ########.fr       */
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

t_stack		*ft_create_stack(int size, char identifier);
t_stack		*ft_destroy_stack(t_stack *stack);
t_stack		*ft_init_stack(int size, char **content, char identifier);
void		ft_print_stack(t_stack *stack);
void		ft_push_stack(t_stack *stack_from, t_stack *stack_to);
void		ft_rotate_stack(t_stack *stack);
void		ft_reverse_rotate_stack(t_stack *stack);
#endif
