/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 07:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/01 23:38:58 by glegendr         ###   ########.fr       */
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

int			main(void)
{
	char *s;
	int i;
	char **tab;
	t_vec vec;
	int fourmis;

	i = 0;
	while (get_next_line(0, &s) == 1)
	{
		tab = tab_join(tab, s);
		free(s);
	}
	if (tab == NULL)
	{
		write(2, "ERROR\n", 5);
		exit(1);
	}
	vec = v_new(sizeof(t_st));
	fourmis = pars(&vec, tab);
	printf("%i\n", fourmis);
	//ft_putchar('\n');
	//ft_putstarstr(tab);
	free(tab);
}
