/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:30:45 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/18 16:28:45 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"
#include "mlx.h"

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int	handle_pause(t_state *state)
{
	(void) state;
	return (0);
}

int	handle_play(t_state *state)
{

	state->is_playing = true;
	return (0);
}

int	handle_next_key(t_state *state)
{
	if (!state->next_instruction)
		return (-1);
	execute_single_instruction(state->next_instruction->content, state->stack_a, state->stack_b);
	render_image(state);
	state->next_instruction = state->next_instruction->next;
	return (0);
}

int	handle_key(int keycode, t_state *state)
{
	if (keycode == 113)
		exit(0);
	if (state->is_playing)
		return (handle_pause(state));
	if (keycode == 112)
		handle_play(state);
	if (keycode == 110)
		return (handle_next_key(state));
	return (0);
}
