/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:29 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/18 16:45:28 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "mlx.h"
#include "stack.h"

#include <stdlib.h>

void	init_image(t_window *window, t_image *image)
{
	ft_printf("Initing image\n");
	image->img = mlx_new_image(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_printf("new image\n");
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), &(image->line_length), &(image->endian));
	ft_printf("data addr\n");
}

void	init_window(t_window *window, t_state *state)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	state->window = window;
	mlx_key_hook(window->win, handle_key, state);
}

void	init_state(t_state *state, t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b, pthread_t *thread_id)
{
	state->instructions_list = instructions_list;
	state->next_instruction = instructions_list;
	state->stack_a = stack_a;
	state->stack_b = stack_b;
	state->window = NULL;
	state->speed = DEFAULT_SPEED;
	state->is_playing = false;
	state->has_finished = false;
	state->play_thread = thread_id;
}
