/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_sort_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:12:41 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/06 17:12:42 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	v_sort_size(t_vec *vec)
{
	int i;
	int y;

	if ((y = v_size(vec)) < 2)
		return ;
	while (y > 0)
	{
		i = 0;
		while (i < v_size(vec) - 1)
		{
			if (v_size((t_vec *)v_get(vec, i)) <
			v_size((t_vec *)v_get(vec, i + 1)))
			{
				v_swap(vec, i, i + 1);
			}
			++i;
		}
		--y;
	}
}
