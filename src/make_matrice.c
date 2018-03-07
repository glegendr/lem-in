/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:52:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/06 23:45:11 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

void		entry_and_end(t_vec *vec)
{
	t_st t;
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		t = *(t_st *)v_get(vec, i);
		if (t.special == 1)
			v_swap(vec, 0, i);
		else if (t.special == 2)
			v_swap(vec, 1, i);
		++i;
	}
}

void		ini_mat(t_mat *mat, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		mat_set(mat, 0, i, 0);
		++i;
	}
}

void		into_mat(t_mat *mat, char **liaisons, char **names)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	x = 0;

	if (liaisons[0] == NULL)
		return;
	while (ft_strcmp(names[i], liaisons[0]) != 0 && names[i])
	{
		++i;
	}
	if (ft_strcmp(names[i], liaisons[0]) != 0)
		exit(1);
	x = i;
	i = 0;
	while (ft_strcmp(names[i], liaisons[1]) != 0 && names[i])
	{
		++i;
	}
	if (ft_strcmp(names[i], liaisons[1]) != 0)
		exit(1);
	y = i;
	mat_set(mat, y, x, 1);
	mat_set(mat, x, y, 1);
}

char		**make_matrice(t_vec *vec, int index, t_mat *mat, char **tab)
{
	int i;
	char **names;
	char **liaisons;
	t_st t;

	i = 0;
	entry_and_end(vec);
	*mat = mat_new(v_size(vec));
	ini_mat(mat, v_size(vec));
	names = (char **)malloc(v_size(vec) + 1);
	while (i < v_size(vec))
	{
		t = *(t_st *)v_get(vec, i);
		names[i] = (char *)malloc(sizeof(char) * ft_strlen(t.nom));
		names[i++] = t.nom;
	}
	names[i] = NULL;
	while (tab[index++])
		if (tab[index - 1][0] != '#')
		{
			liaisons = ft_strsplit(tab[index - 1], '-');
			into_mat(mat, liaisons, names);
			free(liaisons);
		}
	//mat_print(mat, 1);
	return (names);
}
