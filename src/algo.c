/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:44:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/20 22:55:53 by glegendr         ###   ########.fr       */
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
	while (i < mat_size(mat))
	{
		if (mat_get(mat, 0, i) == 1)
		{
			cp += 1;
			break ;
		}
		++i;
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
	int y;
	int size;

	i = 0;
	y = 0;
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
	int i;
	int y;
	t_vec way;
	int ret;
	int size;

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
		{
			//				v_del(&way);
			return (i);
		}
		++i;
	}
	return (i);
}

t_vec		algo(t_rooms *rooms, int ant, int *pathes)
{
	t_vec way;
	t_vec ways;
	int y;
	int i;

	i = 0;
	y = 0;
	ways = v_new(sizeof(t_vec));
	way = dijkstra(rooms);
//		printf("DIJ\n");
	while (v_size(&way) > 1)
	{
		v_push(&ways, &way);
		if (!is_way_acceptable(&ways, ant) ||
				!is_start_or_end_connected(&rooms->edges))
			break ;
		way = dijkstra(rooms);
//		printf("DIJ\n");
	}
	*pathes = nb_of_pathes(&ways, ant);
	/*y = 0;
	  while (y < v_size(&ways))
	  {
	  i = 0;
	  way = *(t_vec *)v_get(&ways, y);
	  while (i < v_size(&way))
	  printf("%i ", *(int *)v_get(&way, i++));
	  printf("\n");
	  ++y;
	  }
	  printf("fin\n");*/
	return (ways);
}
