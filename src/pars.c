/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:34:46 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/01 23:40:56 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

int			into_vec(t_vec *vec, char **tab, int index, int *instruction)
{
	char **tmp;
	int i;
	t_st t;

	i = 0;
	tmp = ft_strsplit(tab[index], ' ');
	while (tmp[i])
		++i;
	if (i != 3)
	{
		free(tmp);
		return (0);
	}
	t.nom = tmp[0];
	t.x = ft_atoi(tmp[1]);
	t.y = ft_atoi(tmp[2]);
	t.special = *instruction;
	*instruction = 0;
	v_push(vec, &t);
	return (1);
}

int			check_instruction(char **tab, int i)
{
	if (!ft_strcmp(tab[i], "##start"))
		return (1);
	else if (!ft_strcmp(tab[i], "##end"))
		return (2);
	else
		return (0);
}

int		pars(t_vec *vec, char **tab)
{
	int i;
	int instruction;

	i = 1;
	instruction = 0;
	while (tab[i])
	{
		if (tab[i][0] == '#')
			instruction = check_instruction(tab, i);
		else if (tab[i][0] != '#')
			if (!into_vec(vec, tab, i, &instruction))
				break ;
		++i;
	}
	i = 0;
	t_st t;
	while (i < v_size(vec))
	{
		t = *(t_st *)v_get(vec, i);
		printf("name = %s, x = %i, y = %i, entree ou sortie ? = %i\n", t.nom, t.x, t.y, t.special);
		++i;
	}
	return (ft_atoi(tab[0]));
}
