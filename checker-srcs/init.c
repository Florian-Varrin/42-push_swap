/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:29 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 18:09:07 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "mlx.h"
#include "stack.h"

void	init_image(t_window *window, t_image *image)
{
	image->img = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), &(image->line_length), &(image->endian));
}

void	init_window(t_window *window, t_state *state)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	state->window = window;
	mlx_key_hook(window->win, handle_key, state);
}

void	init_state(t_state *state, t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b)
{
	state->instructions_list = instructions_list;
	state->next_instruction = instructions_list;
	state->stack_a = stack_a;
	state->stack_b = stack_b;
	state->window = NULL;
}
