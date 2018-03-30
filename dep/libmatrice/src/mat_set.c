/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:34:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/26 21:38:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrice.h"

void		mat_set(t_mat *mat, int y, int x, int content)
{
	mat->private_content[y * mat->private_line_size + x] = content;
}
