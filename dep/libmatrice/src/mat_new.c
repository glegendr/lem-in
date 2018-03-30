/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:24:57 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/26 20:33:46 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrice.h"

t_mat		mat_new(int line_size)
{
	t_mat mat;

	mat.private_line_size = line_size;
	mat.private_content = (int *)malloc(sizeof(int) * (line_size * line_size));
	return (mat);
}
