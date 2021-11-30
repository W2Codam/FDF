/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:14:44 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/12 10:26:28 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_i32 key, t_fdf *data)
{
	if (key == ARROW_UP)
		data->camera.pos.y -= MOVE_SP;
	if (key == ARROW_DOWN)
		data->camera.pos.y += MOVE_SP;
	if (key == ARROW_LEFT)
		data->camera.pos.x -= MOVE_SP;
	if (key == ARROW_RIGHT)
		data->camera.pos.x += MOVE_SP;
	data->camera.pos.x = ft_min(data->camera.pos.x, I32_MAX);
	data->camera.pos.x = ft_max(data->camera.pos.x, I32_MIN);
	data->camera.pos.y = ft_min(data->camera.pos.y, I32_MAX);
	data->camera.pos.y = ft_max(data->camera.pos.y, I32_MIN);
}
