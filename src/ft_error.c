/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 11:21:24 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/09 10:24:26 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(const char	*s)
{
	if (errno)
		perror("Error");
	else
		ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
