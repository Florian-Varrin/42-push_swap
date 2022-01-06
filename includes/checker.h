/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:39:05 by fvarrin           #+#    #+#             */
/*   Updated: 2022/01/06 17:23:54 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stack.h"

void			delete_instruction(void	*instruction);
t_list_el		**parse_instructions(t_list_el **instructions_list);
_Bool			execute_instructions(t_stack *stack_a, t_stack *stack_b,
					t_list_el *instructions_list);
#endif
