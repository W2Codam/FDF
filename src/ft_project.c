/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_project.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:13:27 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/12 10:19:09 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rot_x(int *y, int *z, double x_rot)
{
	int	previous_y;
	int	prev_z;

	previous_y = *y;
	prev_z = *z;
	*y = previous_y * cos(x_rot) + prev_z * sin(x_rot);
	*z = -previous_y * sin(x_rot) + prev_z * cos(x_rot);
}

static void	ft_rot_y(int *x, int *z, double y_rot)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y_rot) + prev_z * sin(y_rot);
	*z = -prev_x * sin(y_rot) + prev_z * cos(y_rot);
}

static void	ft_rot_z(int *x, int *y, double z_rot)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_rot) - prev_y * sin(z_rot);
	*y = prev_x * sin(z_rot) + prev_y * cos(z_rot);
}

// True isometric projection.
/** 
 * True isometric projection.
 * Alternative: 
 * 	*x = (prev_x - z) / sqrt(2);
 *  *y = (prev_x +  prev_y + z) / sqrt(6);
 */
static void	ft_isometric(t_i32 *x, t_i32 *y, t_i32 z)
{
	t_i32	prev_x;
	t_i32	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

t_point	ft_project(t_i32 x, t_i32 y, t_i32 z, t_camera *camera)
{
	x *= camera->zoom;
	y *= camera->zoom;
	z *= (camera->height * camera->zoom) / 100.0f;
	ft_rot_x(&y, &z, camera->x_rot);
	ft_rot_y(&x, &z, camera->y_rot);
	ft_rot_z(&x, &y, camera->z_rot);
	ft_isometric(&x, &y, z);
	x += (WIDTH / 2) + camera->pos.x;
	y += (HEIGHT / 2) + camera->pos.y;
	return (ft_point(x, y));
}
