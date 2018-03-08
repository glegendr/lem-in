/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:18:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/08 03:09:25 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdio.h>

void		print_ant_s_travel(t_ant ant_info, char **names, int *ant_max)
{
	if (ant_info.room == 1)
		*ant_max -= 1;
	else if (ant_info.room == -1 || ant_info.room == 0)
		return ;
	ft_putchar('L');
	ft_putnbr(ant_info.name);
	ft_putchar('-');
	ft_putstr(names[ant_info.room]);
	ft_putchar(' ');
}

void		next_room(t_ant *ant_info, t_vec *ant, int i)
{
	int aah;
	t_ant ant_info_less;
	int y;

	if (ant_info->room == 1 || ant_info->room == -1)
	{
		ant_info->room = -1;
		return ;
	}
	if (i == 0)
	{
		while (ant_info->way[i] != ant_info->room)
			++i;
		ant_info->room = ant_info->way[i + 1];
		return ;
	}
	y = 0;
	while (ant_info->way[y] != ant_info->room)
		++y;
	while (i-- > 0)
	{
		ant_info_less = *(t_ant *)v_get(ant, i);
		if (ant_info_less.room == ant_info->way[y + 1])
			return;
	}
	ant_info->room = ant_info->way[y + 1];
}

void		ini_ant(t_vec *ant, int ant_max, t_vec ways, int name)
{
	t_ant ant_info;
	int i;

	i = v_size(&ways);
	ant_info.way = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (i < v_size(&ways))
	{
		ant_info.way[i] = *(int *)v_get(&ways, i);
		++i;
	}
	ant_info.room = 0;
	while (ant_max > 0)
	{
		--ant_max;
		ant_info.name = name;
		++name;
		v_push(ant, &ant_info);
	}
}

void		ant_s_travel(t_vec ways, int *ants, char **names, int pathes)
{
	int ant_max;
	int i;
	t_vec ant;
	t_ant ant_info;

	i = 0;
	ant_max = 0;
	ant = v_new(sizeof(t_ant));
	while (ants[i])
	{
		ini_ant(&ant, ants[i], *(t_vec *)v_get(&ways, i), ant_max + 1);
		ant_max += ants[i];
		++i;
	}
	while (ant_max > 0)
	{
		i = 0;
		while (i < v_size(&ant))
		{
			next_room(v_get(&ant, i), &ant, i);
			print_ant_s_travel(*(t_ant *)v_get(&ant, i), names, &ant_max);
			++i;
		}
		ft_putchar('\n');
	}
}

void		print_ant(t_vec ways, int pathes, int ant, t_rooms *rooms)
{
	t_vec	way;
	int		*ant_each;
	int		i;
	int		size_bef;

	size_bef = 0;
	i = 0;
	ant_each = (int *)malloc(sizeof(int) * v_size(&ways));
	while (i < v_size(&ways))
		ant_each[i++] = 0;
	i = 0;
	while (ant > 0)
	{
		if (i == v_size(&ways))
		{
			size_bef = 0;
			i = 0;
		}
		way = *(t_vec *)v_get(&ways, i);
		if (i != 0)
		{
			if (v_size(&way) + ant_each[i] < size_bef + ant_each[i - 1])
			{
				++ant_each[i];
				--ant;
				size_bef = v_size(&way);
			}
		}
		else
		{
			++ant_each[i];
			--ant;
			size_bef = v_size(&way);
		}
		++i;
	}
	ant_s_travel(ways, ant_each, rooms->names, pathes);
}
