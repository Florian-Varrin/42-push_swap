/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:48 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/16 10:02:12 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "mlx.h"

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_staight_line(t_image *image, int y_pos, int x_start, int x_end, int color)
{
	while (x_start <= x_end ) {
		put_pixel_to_image(image, x_start++, y_pos, color);
	}
}

void	draw_square(t_image *image, int y_pos, int x_start, int x_end, int height, int color)
{
	int		i;

	i = 0;
	while (i < height)
	{
		draw_staight_line(image, y_pos + i, x_start, x_end, color);;
		i++;
	}
}

