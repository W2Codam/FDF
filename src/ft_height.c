/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_height.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 14:14:44 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/12 10:21:03 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_height(t_i32 key, t_fdf *data)
{
	if (key == KEY_LESS)
		data->camera.height -= HEIGHT_SP;
	if (key == KEY_MORE)
		data->camera.height += HEIGHT_SP;
	data->camera.height = ft_min(data->camera.height, I32_MAX);
	data->camera.height = ft_max(data->camera.height, I32_MIN);
}
