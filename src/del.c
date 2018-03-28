/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:43:43 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/28 22:37:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_ways(t_vec *vec)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		v_del((t_vec *)v_get(vec, i));
		++i;
	}
	v_del(vec);
}

void		del_vec_t_ant(t_vec *vec, int ants)
{
	int i;

	i = 0;
	while (i < ants)
	{
		free(((t_ant *)v_get(vec, i))->way);
		++i;
	}
	v_del(vec);
}

void		del_vec_t_st(t_vec *vec)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		free(((t_st *)v_get(vec, i))->nom);
		++i;
	}
	v_del(vec);
}

void		del_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

void		del_tab_and_t_st(char **tab, t_vec *vec)
{
	del_tab(tab);
	del_vec_t_st(vec);
}
