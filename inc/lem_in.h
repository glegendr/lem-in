/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:54:22 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/03 08:51:31 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "vector.h"

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
}				t_ant;

typedef struct	s_dij
{
	char		*come_from;
	int			lenght;
}				t_dij;

char			**pars(t_vec *vec, char **tmp, t_mat *mat);
char			**make_matrice(t_vec*vec, int i, t_mat *mat, char **tab);
void			algo(t_rooms *rooms, int fourmis);
#endif
