/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:52:05 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/15 18:19:23 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"
#include "mlx.h"

#include <unistd.h>
#include <stdlib.h>

int	handle_key(int keycode, t_state *state)
{
	if (keycode == 113)
		exit(0);
	else if (keycode == 110 && state->next_instruction)
	{
		execute_single_instruction(state->next_instruction->content, state->stack_a, state->stack_b);
		render_image(state);
		state->next_instruction = state->next_instruction->next;
	}
	return (0);
}

int		get_number_width(int number, int max)
{
	int		result;

	result = number * 200 / max;
	return (result + 50);
}

void	render_single_stack(t_stack *stack, t_image *image, int max)
{
	int		i;
	int		n;
	int		number_height;
	int		left_shift;

	number_height = STACK_AREA_HEIGHT / stack->size;
	i = stack->top;
	n = 0;
	if (stack->identifier == 'a')
		left_shift = 0;
	else
		left_shift = 300;
	while (i >= 0) {
		draw_square(image, n * number_height, left_shift, left_shift + get_number_width(stack->arr[i], max), number_height);
		i--;
		n++;
	}
}

void	render_stacks(t_stack *stack_a, t_stack *stack_b, t_image *image)
{
	int		stack_a_max;
	int		stack_b_max;
	int		max_value;

	stack_a_max = stack_max_value(stack_a);
	stack_b_max = stack_max_value(stack_b);
	if (stack_a_max > stack_b_max)
		max_value = stack_a_max;
	else
		max_value = stack_b_max;
	render_single_stack(stack_b, image, max_value);
	render_single_stack(stack_a, image, max_value);
}

void	render_image(t_state *state)
{
	int			i;
	t_list_el	*instruction;
	t_window	*window;
	t_image		image;

	window = state->window;
	init_image(window, &image);
	render_stacks(state->stack_a, state->stack_b, &image);
	mlx_put_image_to_window(window->mlx, window->win, image.img, 0, 0);
	instruction = state->instructions_list;
	i = 1;
	while (instruction) {
		mlx_string_put(window->mlx, window->win, i * 25, 800, 0xFFFFFF, instruction->content);
		instruction = instruction->next;
		i++;
	}

}

void	visualise_instructions(t_list_el *instructions_list, t_stack *stack_a, t_stack *stack_b)
{
	t_window	window;
	t_state		state;

	init_state(&state, instructions_list, stack_a, stack_b);
	init_window(&window, &state);
	render_image(&state);
	mlx_loop(window.mlx);
}
