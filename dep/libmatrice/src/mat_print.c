/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:51:16 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/26 22:15:27 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrice.h"
#include <unistd.h>
#include <stdio.h>

void		mat_print(t_mat *mat, int fd)
{
	int i;

	i = 0;
	while (i < mat->private_line_size * mat->private_line_size)
	{
		ft_putnbr_fd(mat_get(mat, 0, i), fd);
		write(fd, " ", 1);
		if (i % mat->private_line_size - (mat->private_line_size - 1) == 0)
			write(fd, "\n", 1);
		++i;
	}
}
