/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:18:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/21 00:49:30 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

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

void		del_vec_t_ant(t_vec *vec, int *tab, int pathes)
{
	int i;
	int ant_max;

	ant_max = 0;
	i = 0;
	free(((t_ant *)v_get(vec, 0))->way);
	while (i < pathes)
	{
		ant_max += tab[i];
		free(((t_ant *)v_get(vec, ant_max))->way);
		++i;
	}
	v_del(vec);
}

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

int			search_end(int *way)
{
	int i;

	i = 0;
	while (way[i] != 1)
		++i;
	return (i);
}

void		next_room(t_ant *ant_info, t_vec *ant, int i)
{
	t_ant	ant_info_less;
	int		y;

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
		if (ant_info_less.room == ant_info->way[y + 1] &&
				(ant_info_less.room != 1 || search_end(ant_info->way) < 2))
			return ;
	}
	ant_info->room = ant_info->way[y + 1];
}

void		ini_ant(t_vec *ant, int ant_max, t_vec ways, int name)
{
	t_ant	ant_info;
	int		i;

	ant_info.way = (int *)malloc(sizeof(int) * v_size(&ways));
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

void		ant_s_travel(t_vec *ways, int *ants, char **names, int pathes)
{
	int		ant_max;
	int		i;
	t_vec	ant;

	i = 0;
	ant_max = 0;
	ant = v_new(sizeof(t_ant));
	while (i < pathes)
	{
		ini_ant(&ant, ants[i], *(t_vec *)v_get(ways, i), ant_max + 1);
		ant_max += ants[i];
		++i;
	}
	while (ant_max > 0)
	{
		i = 0;
		while (i < v_size(&ant))
		{
			next_room(v_get(&ant, i), &ant, i);
			print_ant_s_travel(*(t_ant *)v_get(&ant, i++), names, &ant_max);
		}
		ft_putchar('\n');
	}
	del_vec_t_ant(&ant, ants, pathes);
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
	ant_s_travel(&ways, ant_each, rooms->names, pathes);
	free(ant_each);
	del_ways(&ways);
}
