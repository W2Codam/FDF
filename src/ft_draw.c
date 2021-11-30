/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 10:32:05 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/03 22:59:10 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_put_screen(t_fdf *data)
{	
	t_i32	y;

	y = 0;
	ft_put_canvas(&data->instance, data->canvas, ft_point(0, 0));
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 20, \
	WHITE, "How to Use");
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 35, \
	WHITE, "Zoom: PAGE UP/DOWN");
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 30, \
	WHITE, "Move: Arrows");
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 30, \
	WHITE, "Flatten: </>");
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 30, \
	WHITE, "Reset: 0");
	mlx_string_put(data->instance.mlx, data->instance.win, 15, y += 30, \
	WHITE, "Rotate:");
	mlx_string_put(data->instance.mlx, data->instance.win, 57, y += 25, \
	WHITE, "X-Axis: W/S");
	mlx_string_put(data->instance.mlx, data->instance.win, 57, y += 25, \
	WHITE, "Y-Axis: A/D");
	mlx_string_put(data->instance.mlx, data->instance.win, 57, y += 25, \
	WHITE, "Z-Axis: Q/E");
}

static t_i32	ft_get(t_i32 x, t_i32 y, t_fdf *data)
{
	return (data->coords[y * data->map_width + x].height);
}

static void	ft_draw_background(t_fdf *data)
{
	t_i32	i;

	i = 0;
	ft_bzero(data->canvas->pixels, WIDTH * HEIGHT * \
	(data->canvas->bits_per_pixel / 8));
	while (i < WIDTH * HEIGHT)
	{
		((t_i32 *)data->canvas->pixels)[i] = 0x222222;
		i++;
	}
}

static void	ft_drawlines(t_i32 x, t_i32 y, t_fdf *data)
{
	if (x != data->map_width - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data), &data \
		->camera), ft_project(x + 1, y, ft_get(x + 1, y, data), &data->camera));
	if (y != data->map_height - 1)
		ft_draw_line(data->canvas, ft_project(x, y, ft_get(x, y, data), &data \
		->camera), ft_project(x, y + 1, ft_get(x, y + 1, data), &data->camera));
}

void	ft_draw(t_fdf *data)
{
	t_i32	x;
	t_i32	y;

	x = 0;
	y = 0;
	ft_draw_background(data);
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_drawlines(x, y, data);
			x++;
		}
		y++;
	}
	ft_put_screen(data);
}
