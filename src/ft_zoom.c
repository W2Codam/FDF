/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zoom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:14:44 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/12 10:38:22 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_i32 key, t_fdf *data)
{
	if (key == KEY_UP)
		data->camera.zoom += ZOOM_SP;
	if (key == KEY_DOWN)
		data->camera.zoom -= ZOOM_SP;
	data->camera.zoom = ft_max(data->camera.zoom, 0);
	data->camera.zoom = ft_min(data->camera.zoom, I32_MAX);
}
