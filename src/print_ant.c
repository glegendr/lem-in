/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:18:20 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/07 00:39:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ant_s_travel(t_vec *ways, int *ants, char **names, int pathes)
{
//	int ant_nb;
//	ft_printf("L%i-%s", ant_nb);

}

void		print_ant(t_vec ways, int pathes, int ant, t_rooms *rooms)
{
	t_vec way;
	int		*ant_each;
	int		i;
	int size_bef;

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
		int y = 0;
	while (y++ < v_size(&ways))
		printf("chemin num %i a %i fourmis\n", y, ant_each[y - 1]);
}
