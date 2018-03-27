/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:18:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/27 21:01:07 by glegendr         ###   ########.fr       */
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

void		ant_s_travel(t_vec *ways, int *ants, char **names, int pathes)
{
	int		ant_max;
	int		i;
	t_vec	ant;
	int		nb_ants;

	i = 0;
	nb_ants = 0;
	while (ants[i] != 0)
		nb_ants += ants[i++];
	i = 0;
	ant_max = 0;
	ant = v_new(sizeof(t_ant));
	while (ant_max <= nb_ants)
	{
		if (i == pathes)
			i = 0;
		if (ants[i] != 0)
		{
			ini_ant(&ant, ++ant_max, *(t_vec *)v_get(ways, i));
			ants[i] -= 1;
		}
		else if (i == 0 && ants[i] == 0)
			break ;
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
	del_vec_t_ant(&ant, nb_ants);
}

void		print_way(t_vec *ways)
{
	t_vec	tmp;
	int		i;
	int		y;

	i = 0;
	while (i < v_size(ways))
	{
		tmp = *(t_vec *)v_get(ways, i);
		++i;
		y = 0;
		while (y < v_size(&tmp))
		{
			printf("%i ", *(int *)v_get(&tmp, y++));
		}
		printf("\n");
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
	ant_each = (int *)malloc(sizeof(int) * (v_size(&ways) + 1));
	while (i <= v_size(&ways))
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
