/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 07:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/09 01:19:40 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "matrice.h"
#include "lem_in.h"

void		del_vec_t_st(t_vec *vec)
{
	t_st *t;
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		t = v_get(vec, i);
//		free(t->nom);
		++i;
	}
	//v_del(vec);
}

void		del_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
//		free(tab[i]);
		++i;
	}
//	free(tab);
}

void		error(char *s)
{
	write(2, "ERROR", 5);
	if (s[0] != '\0')
		write(2, ": ", 2);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

char		**tab_join(char **tab, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	if (tab == NULL)
	{
		tab = (char **)malloc(sizeof(char *) * 2);
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	while (tab[i])
		++i;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		++i;
	}
	del_tab(tab);
	tmp[i] = ft_strdup(s);
	tmp[i + 1] = NULL;
	return (tmp);
}

char		**read_instructions(int *ant, char *fichier)
{
	char **tab;
	char *s;
	int i;

	int fd = open(fichier, O_RDONLY);
	tab = NULL;
	s = NULL;
	while (get_next_line(fd, &s) == 1)
	{
		tab = tab_join(tab, s);
//		free(s);
	}
	if (tab == NULL)
	{
		del_tab(tab);
		error("");
	}
	i = 0;
	while (tab[0][i++])
		if (tab[0][i - 1] > '9' || tab[0][i - 1] < '0')
		{
			del_tab(tab);
			error("ant number is not well formed");
		}
	*ant = ft_atoi(tab[0]);
	return (tab);
}

void		into_rooms(t_rooms *rooms, char **names, t_mat mat)
{
	int i;

	i = 0;
	while (names[i])
		++i;
	rooms->names = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (names[i])
	{
		rooms->names[i] = (char *)malloc(sizeof(char) * ft_strlen(names[i]));
		rooms->names[i] = names[i];
		++i;
	}
	rooms->edges = mat;
}

int			main(int ac, char **argv)
{
	char **tab;
	t_vec vec;
	t_mat mat;
	int ant;
	t_rooms rooms;
	int pathes;

	pathes = 0;
	tab = read_instructions(&ant, argv[1]);
	if (ant <= 0)
	{
		del_tab(tab);
		error("ant number is not well formed");
	}
	vec = v_new(sizeof(t_st));
	tab = pars(&vec, tab, &mat);
	into_rooms(&rooms, tab, mat);
	print_ant(algo(&rooms, ant, &pathes), pathes, ant, &rooms);
	mat_del(&mat);
	del_vec_t_st(&vec);
	//del_tab(tab);
//		while (1);
}
