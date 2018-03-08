/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:34:46 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/08 03:56:37 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

void		check_vector(t_vec *vec)
{
	t_st t;
	int i;
	int inst;
	int y;

	i = 0;
	inst = 0;
	while (i < v_size(vec))
	{
		t = *(t_st *)v_get(vec, i);
			if (t.special == 1 || t.special == 2)
				inst += 1;
		++i;
	}
	if (inst != 2)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
}

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
	t.nom = (char *)malloc(sizeof(char) * ft_strlen(tmp[0]));
	t.nom = tmp[0];
	t.special = *instruction;
	*instruction = 0;
	v_push(vec, &t);
	return (1);
}

int			check_instruction(char **tab, int i, int *ad)
{
	if (*ad != 10 && *ad != 11 && *ad != 1 && *ad != 0)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	if (!ft_strcmp(tab[i], "##start"))
	{
		*ad += 10;
		return (1);
	}
	else if (!ft_strcmp(tab[i], "##end"))
	{
		*ad += 1;
		return (2);
	}
	else
		return (0);
}

char		**pars(t_vec *vec, char **tab, t_mat *mat)
{
	int i;
	int instruction;
	int check_ad;

	check_ad = 0;
	i = 1;
	instruction = 0;
	while (tab[i])
	{
		if (tab[i][0] == '#')
			instruction = check_instruction(tab, i, &check_ad);
		else if (tab[i][0] != '#')
			if (!into_vec(vec, tab, i, &instruction))
				break ;
		++i;
	}
	if (check_ad != 11)
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	check_vector(vec);
	tab = make_matrice(vec, i, mat, tab);
	return (tab);
}
