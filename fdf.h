/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 18:43:46 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/30 10:10:36 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
░██╗░░░░░░░██╗██████╗░░░░░███████╗██████╗░███████╗
░██║░░██╗░░██║╚════██╗░░░░██╔════╝██╔══██╗██╔════╝
░╚██╗████╗██╔╝░░███╔═╝░░░░█████╗░░██║░░██║█████╗░░
░░████╔═████║░██╔══╝░░░░░░██╔══╝░░██║░░██║██╔══╝░░
░░╚██╔╝░╚██╔╝░███████╗░░░░██║░░░░░██████╔╝██║░░░░░
░░░╚═╝░░░╚═╝░░╚══════╝░░░░╚═╝░░░░░╚═════╝░╚═╝░░░░░
*/

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "libmlx.h"
# include "fcntl.h"
# define WIDTH 1920
# define HEIGHT 1080
# define ROT_SP 0.05
# define MOVE_SP 10
# define ZOOM_SP 2
# define HEIGHT_SP 2

//= Types =//

/** 
 * @param x_rot The X rotation.
 * @param y_rot The Y rotation.
 * @param z_rot The Z rotation.
 * @param pos2d The 2D camera position.
 * @param zoom The zoom amount.
 * @param height The height modification.
 */
typedef struct s_camera
{
	double	x_rot;
	double	y_rot;
	double	z_rot;
	t_point	pos;
	t_i32	zoom;
	t_i32	height;
}	t_camera;

typedef struct s_coords
{
	t_i32	height;
	t_i32	color;
}	t_coords;

/** 
 * Struct wrapping up our mlx insatnce and main drawing canvas.
 * @param instance The MLX instance.
 * @param canvas The main canvas buffer.
 * @param map_height The num of coordinates in the height.
 * @param map_width The num of coordinates in the width.
 */
typedef struct s_fdf
{
	t_mlx		instance;
	t_camera	camera;
	t_canvas	*canvas;
	t_i32		map_height;
	t_i32		map_width;
	t_coords	*coords;
}	t_fdf;

//= Functions =//

void		ft_move(t_i32 key, t_fdf *data);
void		ft_height(t_i32 key, t_fdf *data);
void		ft_rotate(t_i32 key, t_fdf *data);
void		ft_zoom(t_i32 key, t_fdf *data);

/** 
 * Projects a vector3 to the screen with respects to the cameras state.
 * That is, it converts a 3D coordinate to 2D Screen space.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param z The z coordinate.
 * @param camera The camera.
 */
t_point		ft_project(t_i32 x, t_i32 y, t_i32 z, t_camera *camera);

/** 
 * Draws the canvas to the screen.
 * @param data The FDF instance.
 */
void		ft_draw(t_fdf *data);

/**
 * Parses the given map into a 1D coordinate array.
 * Also populates the data ptr with important info (map width, ...)
 * 
 * @param data The fdf data ptr.
 * @param map_path The file path to the map to open.
 * @return A 1D coordinate array.
 */
t_coords	*ft_parse_map(t_fdf *data, char *map_path);

/**
 * Assertion method, if called will quit/exit the program.
 * 
 * @param s The error message.
 */
void		ft_error(const char	*s);
#endif