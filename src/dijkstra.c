/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:46:18 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/21 00:41:49 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_pathes(t_mat *mat, t_vec vec)
{
	int i;
	int y;

	y = 1;
	mat_set(mat, *(int *)v_get(&vec, y), 0, 0);
	mat_set(mat, 0, *(int *)v_get(&vec, y), 0);
	while (y < v_size(&vec) - 1)
	{
		i = 0;
		while (i < mat_size(mat))
		{
			mat_set(mat, *(int *)v_get(&vec, y), i, 0);
			mat_set(mat, i, *(int *)v_get(&vec, y), 0);
			++i;
		}
		++y;
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

int			make_children(t_vec *queue, t_mat *edges)
{
	int		i;
	t_vec	tmp;
	t_vec	child;
	int		ret;

	ret = 0;
	i = 0;
	if (v_size(queue) < 1)
		return (-1);
	tmp = v_copy(v_get(queue, v_size(queue) - 1));
	v_del(v_get(queue, v_size(queue) - 1));
	v_del_last(queue);
	while (i++ < mat_size(edges) && ret == 0)
		if (mat_get(edges, *(int *)v_get(&tmp, v_size(&tmp) - 1), i - 1) == 1
				&& isn_t_in_vec(&tmp, i - 1) == 1)
		{
			child = v_copy(&tmp);
			v_push_int(&child, i - 1);
			v_push_first(queue, &child);
			if (i - 1 == 1)
				ret = 1;
		}
	v_del(&tmp);
	return (ret);
}

t_vec		dijkstra(t_rooms *rooms)
{
	t_vec	queue;
	t_vec	way;
	int		ret;

	way = v_new(sizeof(int));
	queue = v_new(sizeof(t_vec));
	v_push_int(&way, 0);
	v_push(&queue, &way);
	while ((ret = make_children(&queue, &rooms->edges)) == 0)
		v_sort_size(&queue);
	if (ret == -1)
		return (way);
	del_pathes(&rooms->edges, *(t_vec *)v_get(&queue, 0));
	way = v_copy((t_vec *)v_get(&queue, 0));
	del_ways(&queue);
	return (way);
}
