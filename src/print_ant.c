/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:18:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/03 16:24:16 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

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

t_vec		give_antmax_value(int *ants, int nb_ants, int pathes, t_vec *ways)
{
	int		i;
	int		ant_max;
	t_vec	ant;

	ant = v_new(sizeof(t_ant));
	i = 0;
	ant_max = 0;
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
	return (ant);
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
	ant = give_antmax_value(ants, nb_ants, pathes, ways);
	ant_max = nb_ants;
	while (ant_max > 0)
	{
		i = 0;
		while (i < v_size(&ant))
		{
			if (next_room((t_ant *)v_get(&ant, i), &ant, i))
				print_ant_s_travel(*(t_ant *)v_get(&ant, i), names, &ant_max);
			++i;
		}
		ft_putchar('\n');
	}
	del_vec_t_ant(&ant, nb_ants);
}

int			check_pathes(t_vec ways, char **tab, int *i, int *size_bef)
{
	int pathes;

	if ((pathes = v_size(&ways)) == 0)
		error("no way founded");
	ft_putstarstr(tab);
	write(1, "\n", 1);
	*size_bef = 0;
	*i = 0;
	return (pathes);
}

void		print_ant(t_vec ways, char **tab, int ant, t_rooms *rooms)
{
	t_vec	way;
	int		*ant_each;
	int		i;
	int		size_bef;
	int		pathes;

	pathes = check_pathes(ways, tab, &i, &size_bef);
	ant_each = ini_ant_each(ways);
	while (ant > 0)
	{
		if (i == v_size(&ways))
			i_to_0(&size_bef, &i);
		way = *(t_vec *)v_get(&ways, i);
		if ((v_size(&way) + ant_each[i] < size_bef + ant_each[i - 1] && i != 0)
				|| i == 0)
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
