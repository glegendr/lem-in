/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:44:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/30 13:14:31 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

int			is_start_or_end_connected(t_mat *mat)
{
	int i;
	int cp;

	cp = 0;
	i = 0;
	while (i++ < mat_size(mat))
		if (mat_get(mat, 0, i - 1) == 1)
		{
			cp += 1;
			break ;
		}
	i = 0;
	while (i < mat_size(mat))
	{
		if (mat_get(mat, 1, i) == 1)
		{
			cp += 1;
			break ;
		}
		++i;
	}
	if (cp == 2)
		return (1);
	return (0);
}

int			is_way_acceptable(t_vec *ways, int ant)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (v_size(ways) < 1)
		return (1);
	while (i < v_size(ways))
	{
		size += v_size((t_vec *)v_get(ways, i)) - 1;
		++i;
	}
	if ((ant + size) / v_size(ways) - 1 >
			(ant + size + v_size((t_vec *)v_get(ways, i - 1)) - 1) /
			(v_size(ways) + 1) - 1)
		return (1);
	return (0);
}

int			nb_of_pathes(t_vec *ways, int ant)
{
	int		i;
	t_vec	way;
	int		ret;
	int		size;

	i = 0;
	size = 0;
	ret = 2147483647;
	while (i < v_size(ways))
	{
		way = *(t_vec *)v_get(ways, i);
		size += v_size(&way) - 1;
		if (ret > ((ant + size) / (i + 1)) - 1)
			ret = ((ant + size) / (i + 1)) - 1;
		else
			return (i);
		++i;
	}
	return (i);
}

t_vec		algo(t_rooms *rooms)
{
	t_vec	way;
	t_vec	ways;
	int	paths;

	ways = v_new(sizeof(t_vec));
	paths = v_size(&ways);
	way = dijkstra(rooms, paths);
	while (v_size(&way) > 1)
	{
		v_push(&ways, &way);
		paths = v_size(&ways);
		if (!is_start_or_end_connected(&rooms->edges))
			break ;
		way = dijkstra(rooms, paths);
	}
	return (ways);
}
