/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_print_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:28:26 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/03 16:21:51 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int			*ini_ant_each(t_vec ways)
{
	int i;
	int *ant_each;

	i = 0;
	if ((ant_each = (int *)malloc(sizeof(int) * (v_size(&ways) + 1))) == NULL)
		return (0);
	while (i <= v_size(&ways))
		ant_each[i++] = 0;
	return (ant_each);
}

int			is_someone_in_my_room(int room, t_vec *ants, int my_room)
{
	t_ant	tmp;
	int		i;
	int		y;

	i = 0;
	while (i < v_size(ants))
	{
		y = 0;
		tmp = *(t_ant *)v_get(ants, i);
		if (tmp.room == room && room != 1)
			return (1);
		if (room == 1 && tmp.room == room)
		{
			while (tmp.way[y + 1] != 1)
				++y;
			if (tmp.way[y] == my_room)
				return (1);
		}
		++i;
	}
	return (0);
}

int			search_end(int *way)
{
	int i;

	i = 0;
	while (way[i] != 1)
		++i;
	return (i);
}

int			next_room(t_ant *ant_info, t_vec *ant, int i)
{
	int		y;

	if (ant_info->room == -1)
		return (0);
	if (ant_info->room == 1)
	{
		ant_info->room = -1;
		ant_info->name = 0;
		return (0);
	}
	if (i == 0)
	{
		while (ant_info->way[i] != ant_info->room)
			++i;
		ant_info->room = ant_info->way[i + 1];
		return (1);
	}
	y = 0;
	while (ant_info->way[y] != ant_info->room)
		++y;
	if (is_someone_in_my_room(ant_info->way[y + 1], ant, ant_info->way[y]))
		return (0);
	ant_info->room = ant_info->way[y + 1];
	return (1);
}

void		ini_ant(t_vec *ant, int name, t_vec tmp)
{
	t_ant	ant_info;
	int		i;

	if ((ant_info.way = (int *)malloc(sizeof(int) * v_size(&tmp))) == NULL)
		return ;
	i = 0;
	ant_info.room = 0;
	ant_info.name = name;
	while (i < v_size(&tmp))
	{
		ant_info.way[i] = *(int *)v_get(&tmp, i);
		++i;
	}
	v_push(ant, &ant_info);
}
