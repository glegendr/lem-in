/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:54:22 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/09 00:38:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "vector.h"
# include "matrice.h"

typedef struct	s_st
{
	char		*nom;
	int			special;
}				t_st;

typedef struct	s_rooms
{
	char		**names;
	t_mat		edges;
}				t_rooms;

typedef struct	s_ant
{
	int			name;
	int			room;
	int			*way;
}				t_ant;

typedef struct	s_dij
{
	char		*come_from;
	int			lenght;
}				t_dij;

void			del_tab(char **tab);
void			error(char *s);
void			print_ant(t_vec ways, int pathes, int ant, t_rooms *rooms);
char			**pars(t_vec *vec, char **tmp, t_mat *mat);
char			**make_matrice(t_vec*vec, int i, t_mat *mat, char **tab);
t_vec			algo(t_rooms *rooms, int fourmis, int *pathes);
#endif
