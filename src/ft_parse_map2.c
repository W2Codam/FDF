/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_map2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 11:18:38 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/16 10:25:37 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_i32	ft_get_width(char *line)
{	
	t_i32	count;

	count = 0;
	while (*line && *line != '\n')
	{
		while (*line == ' ' && *line)
			line++;
		if (ft_isdigit(*line) || *line == '-')
			count++;
		while (*line != ' ' && *line)
		{
			if (*line == '\n')
				break ;
			line++;
		}
	}
	return (count);
}

static	t_i32	ft_count(char *line)
{
	t_i32	count;

	count = 0;
	while (*line)
	{
		while (ft_isspace(*line) && *line)
			line++;
		if (ft_isdigit(*line) || *line == '-')
			count++;
		while (!ft_isspace(*line) && *line)
			line++;
	}
	return (count);
}

static t_coords	*ft_process(t_fdf *data, char *line)
{
	t_i32		i;
	t_i32		size;
	t_coords	*coords;
	char		*linecpy;

	i = 0;
	linecpy = line;
	size = ft_count(linecpy);
	coords = ft_calloc(size + 1, sizeof(t_coords));
	while (i < size)
	{
		while (ft_isspace(*linecpy) && *linecpy)
			linecpy++;
		coords[i].height = ft_atoi(linecpy);
		while (!ft_isspace(*linecpy) && *linecpy)
			linecpy++;
		i++;
	}
	data->map_width = ft_get_width(line);
	free(line);
	return (coords);
}

t_coords	*ft_parse_map(t_fdf *data, char *map_path)
{
	t_i32		fd;
	t_i32		bread;
	char		*readstr;
	char		*line;

	bread = 1;
	readstr = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0 || !ft_strnstr(map_path, ".fdf", ft_strlen(map_path)))
		ft_error("Invalid file or extension!");
	while (true)
	{
		line = ft_get_next_line(fd);
		if (line)
		{
			readstr = ft_str_append(readstr, line);
			data->map_height++;
		}
		else
			break ;
		free(line);
	}
	close(fd);
	return (ft_process(data, readstr));
}
