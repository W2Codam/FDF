/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 18:11:53 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/16 10:21:37 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_i32	ft_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_new_camera(t_fdf *data)
{
	data->camera.pos = ft_point(0, -100);
	data->camera.x_rot = 0;
	data->camera.y_rot = 0;
	data->camera.z_rot = 0;
	data->camera.height = 50;
	data->camera.zoom = 20;
}

t_i32	ft_press(t_i32 key, void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	if (key == KEY_ESC)
		ft_close(param);
	if (key == KEY_DOWN || key == KEY_UP)
		ft_zoom(key, data);
	if (key == ARROW_UP || key == ARROW_DOWN || \
		key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_move(key, data);
	if (key == KEY_Q || key == KEY_E || \
		key == KEY_W || key == KEY_A || \
		key == KEY_S || key == KEY_D)
		ft_rotate(key, data);
	if (key == KEY_LESS || key == KEY_MORE)
		ft_height(key, data);
	if (key == KEY_0)
		ft_new_camera(data);
	ft_draw(data);
	return (0);
}

int	main(t_i32 argc, char **argv)
{
	t_fdf		data;

	if (argc == 1 || argc > 2)
	{
		ft_putendl("USAGE: ./fdf <map_file>");
		exit(EXIT_SUCCESS);
	}
	data.coords = ft_parse_map(&data, argv[1]);
	if (ft_init(&data.instance, WIDTH, HEIGHT, "W2FDF"))
	{
		data.canvas = ft_create_canvas(&data.instance, WIDTH, HEIGHT);
		ft_new_camera(&data);
		ft_draw(&data);
		mlx_hook(data.instance.win, DESTROY_NOTIFY, 0, ft_close, &data);
		mlx_hook(data.instance.win, KEY_PRESS, 0, ft_press, &data);
		mlx_loop(data.instance.mlx);
		exit(EXIT_SUCCESS);
	}
	ft_error("Error: Initilization failure!");
	return (0);
}
