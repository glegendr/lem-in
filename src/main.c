/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 07:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/30 13:19:18 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "matrice.h"
#include "lem_in.h"

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

char		**read_instructions(int *ant)
{
	char	**tab;
	char	*s;
	int		i;
	int		ret;

	tab = NULL;
	s = NULL;
	while ((ret = get_next_line(0, &s)) == 1)
	{
		tab = tab_join(tab, s);
		free(s);
	}
	if (ret == -1 || tab == NULL)
		error("read error");
	i = 0;
	while (tab[0][i++])
		if (tab[0][i - 1] > '9' || tab[0][i - 1] < '0')
		{
			del_tab(tab);
			error("ant number is not well formed");
		}
	*ant = ft_atolli(tab[0]);
	return (tab);
}

void		into_rooms(t_rooms *rooms, char **names, t_mat mat)
{
	int i;

	i = 0;
	while (names[i])
		++i;
	if ((rooms->names = (char **)malloc(sizeof(char *) * i + 1)) == NULL)
		return ;
	i = 0;
	while (names[i])
	{
		rooms->names[i] = ft_strdup(names[i]);
		++i;
	}
	rooms->names[i] = NULL;
	rooms->edges = mat;
}

int			main(void)
{
	char	**tab;
	t_mat	mat;
	int		ant;
	t_rooms	rooms;
	char	**names;

	tab = read_instructions(&ant);
	if (ant <= 0)
	{
		del_tab(tab);
		error("ant number is not well formed");
	}
	names = pars(tab, &mat);
	into_rooms(&rooms, names, mat);
	print_ant(algo(&rooms), tab, ant, &rooms);
	mat_del(&mat);
	del_tab(tab);
	del_tab(names);
	del_tab(rooms.names);
}
