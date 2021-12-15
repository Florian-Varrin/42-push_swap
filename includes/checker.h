/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:39:05 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 18:16:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include "stack.h"
#include <stdbool.h>

# define STACK_AREA_HEIGHT 700
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT STACK_AREA_HEIGHT + 300
# define WINDOW_NAME "Push Swap"
# define COLOR 0x292D39

typedef struct	s_window {
	void		*mlx;
	void		*win;
}	t_window;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_state {
	t_window	*window;
	t_list_el	*instructions_list;
	t_list_el	*next_instruction;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_state;

// Instructions
void		delete_instruction(void	*instruction);
t_list_el	*parse_instructions();
_Bool		execute_single_instruction(char *instruction, t_stack *stack_a, t_stack *stack_b);
_Bool		execute_instructions(t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b);
void		visualise_instructions(t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b);

// Visualise
void		init_image(t_window *window, t_image *image);
void		init_window(t_window *window, t_state *state);
void		init_state(t_state *state, t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b);
int			handle_key(int keycode, t_state *state);

// Draw
void		draw_staight_line(t_image *image, int y_pos, int x_start, int x_end);
void		draw_square(t_image *image, int y_pos, int x_start, int x_end, int height);
void		render_image(t_state *state);
#endif
