/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:14:44 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/03 22:58:42 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_i32 key, t_fdf *data)
{
	if (key == KEY_Q)
		data->camera.z_rot += ROT_SP;
	if (key == KEY_E)
		data->camera.z_rot -= ROT_SP;
	if (key == KEY_W)
		data->camera.x_rot -= ROT_SP;
	if (key == KEY_S)
		data->camera.x_rot += ROT_SP;
	if (key == KEY_A)
		data->camera.y_rot -= ROT_SP;
	if (key == KEY_D)
		data->camera.y_rot += ROT_SP;
}
