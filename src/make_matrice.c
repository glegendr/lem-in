/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:52:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/29 00:53:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrice.h"
#include "lem_in.h"

void		entry_and_end(t_vec *vec)
{
	t_st	t;
	int		i;

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
	if (liaisons[0] == NULL || liaisons[1] == NULL || liaisons[2] != NULL)
		error("");
	while (ft_strcmp(names[i], liaisons[0]))
	{
		++i;
		if (names[i] == NULL && ft_strcmp(names[i - 1], liaisons[0]))
			error("");
	}
	x = i;
	i = 0;
	while (ft_strcmp(names[i], liaisons[1]) != 0 && names[i])
	{
		++i;
		if (names[i] == NULL && ft_strcmp(names[i - 1], liaisons[1]))
			error("");
	}
	y = i;
	mat_set(mat, y, x, 1);
	mat_set(mat, x, y, 1);
}

char		**ini_names(t_vec *vec)
{
	int		i;
	char	**names;
	t_st	t;

	i = 0;
	names = (char **)malloc(sizeof(char *) * (v_size(vec) + 1));
	while (i < v_size(vec))
	{
		t = *(t_st *)v_get(vec, i);
		names[i++] = ft_strdup(t.nom);
		if (t.nom[0] == 'L')
			error("invalid room name");
	}
	names[i] = NULL;
	return (names);
}

char		**make_matrice(t_vec *vec, int index, t_mat *mat, char **tab)
{
	char	**names;
	char	**liaisons;

	if (tab[index] == NULL)
		error("inexisting ways");
	entry_and_end(vec);
	*mat = mat_new(v_size(vec));
	ini_mat(mat, v_size(vec));
	names = ini_names(vec);
	while (tab[index++])
		if (tab[index - 1][0] != '#')
		{
			liaisons = ft_strsplit(tab[index - 1], '-');
			into_mat(mat, liaisons, names);
			del_tab(liaisons);
		}
	del_tab_and_t_st(tab, vec);
	return (names);
}
