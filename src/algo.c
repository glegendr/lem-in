/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:44:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/12 23:49:16 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

void		del_queue(t_vec *vec)
{
	t_vec *tmp;

	while (v_size(vec) > 0)
	{
		tmp = (t_vec *)v_pop(vec);
		//		v_del(tmp);
	}
	//	v_del(vec);
}

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
			//			v_del(&way);
			return (i);
		}
		++i;
	}
	return (i);
}

t_vec		v_del_path(t_vec *queue, t_mat *edges)
{
	t_vec tmp;
	int i;
	int y;

	i = 1;
	y = 1;
	while (v_size(queue) > 0)
	{
		tmp = *(t_vec *)v_pop(queue);
		if (*(int *)v_get(&tmp, v_size(&tmp) - 1) == 1)
		{
			mat_set(edges, 0, *(int *)v_get(&tmp, 1), 0);
			mat_set(edges, *(int *)v_get(&tmp, 1), 0, 0);
			while (y < v_size(&tmp) - 1)
			{
				i = 0;
				while (i < mat_size(edges))
				{
					mat_set(edges, *(int *)v_get(&tmp, y), i, 0);
					mat_set(edges, i++, *(int *)v_get(&tmp, y), 0);
				}
				++y;
			}
			del_queue(queue);
			return (tmp);
		}
		//		v_del(&tmp);
	}
}

int			isn_t_in_vec(t_vec *vec, int nb)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		if (nb == *(int *)v_get(vec, i))
			return (0);
		++i;
	}
	return (1);
}

int			push_children(t_vec *queue, t_mat *edges)
{
	int i;
	t_vec parent;
	t_vec child;
	int ret;

	ret = 0;
	i = 0;
	if (v_size(queue) < 1)
		return (-1);
	parent = *(t_vec *)v_pop(queue);
	while (i < mat_size(edges))
	{
		if (mat_get(edges, *(int *)v_get(&parent, v_size(&parent) - 1), i) == 1
				&& isn_t_in_vec(&parent, i) == 1)
		{
			child = v_copy(&parent);
			v_push_int(&child, i);
			v_push(queue, &child);
			if (i == 1)
				ret = 1;
			//	v_del(&child);
		}
		++i;
	}
	//	v_del(&parent);
	return (ret);
}

t_vec		dijkstra(t_rooms *rooms)
{
	t_vec queue;
	t_vec way;
	int ret;
	int i = 0;

	way = v_new(sizeof(int));
	queue = v_new(sizeof(t_vec));
	v_push_int(&way, 0);
	v_push(&queue, &way);
	while ((ret = push_children(&queue, &rooms->edges)) == 0)
	{
		//		printf("%i\n", v_size(&queue));
		//	if (v_size(&queue) > 3000)
		//		printf("HIih\n");
		v_sort_size(&queue);
	}
	if (ret == -1)
	{
		v_del(&queue);
		return (way);
	}
	v_del(&way);
	return (v_del_path(&queue, &rooms->edges));
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
	while (v_size(&way) > 1)
	{
		v_push(&ways, &way);
		if (!is_way_acceptable(&ways, ant) ||
				!is_start_or_end_connected(&rooms->edges))
			break ;
		way = dijkstra(rooms);
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
