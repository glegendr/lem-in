/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 07:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/03 08:45:20 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "matrice.h"
#include "lem_in.h"

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
	free(tab);
	tmp[i] = ft_strdup(s);
	tmp[i + 1] = NULL;
	return (tmp);
}

char		**read_instructions(int *ant, char *fichier)
{
	char **tab;
	char *s;
	int fd = open(fichier, O_RDONLY);
	tab = NULL;
	s = NULL;
	while (get_next_line(fd, &s) == 1)
	{
		tab = tab_join(tab, s);
		free(s);
	}
	if (tab == NULL)
	{
		write(2, "ERROR\n", 6);
		exit(1);
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

	tab = read_instructions(&ant, argv[1]);
	if (ant <= 0)
	{
		free(tab);
		write(2, "ERROR\n", 6);
		return (0);
	}
	vec = v_new(sizeof(t_st));
	tab = pars(&vec, tab, &mat);
	v_del(&vec);
	into_rooms(&rooms, tab, mat);
	//free(tab);
	algo(&rooms, ant);
	mat_del(&mat);
	printf("fourmis = %i\n", ant);
}
