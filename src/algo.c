/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:44:21 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/03 09:07:22 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

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
			return (tmp);
		}
	}
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
		if (mat_get(edges, *(int *)v_get(&parent, v_size(&parent) - 1), i) == 1)
		{
			child = v_copy(&parent);
			v_push_int(&child, i);
			v_push(queue, &child);
			if (i == 1)
				ret = 1;
		}
		++i;
	}
	return (ret);
}

t_vec		dijkstra(t_rooms *rooms)
{
	t_vec queue;
	t_vec way;
	int ret;

	way = v_new(sizeof(int));
	queue = v_new(sizeof(t_vec));
	v_push_int(&way, 0);
	v_push(&queue, &way);
	while ((ret = push_children(&queue, &rooms->edges)) == 0)
		v_sort_size(&queue);
	if (ret == -1)
		return (way);
	return (v_del_path(&queue, &rooms->edges));
}

void		algo(t_rooms *rooms, int ant)
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
		way = dijkstra(rooms);
	}
	while (i < v_size(&ways))
	{
		way = *(t_vec *)v_get(&ways, i);
		y = 0;
		while (y < v_size(&way))
		{
			printf("%i", *(int *)v_get(&way, y));
			++y;
			if (y < v_size(&way))
				printf("->");
		}
		printf("\n");
		++i;
	}
	return ;
}
