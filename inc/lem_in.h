/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:54:22 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/30 15:01:13 by glegendr         ###   ########.fr       */
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

void			i_to_0(int *i, int *y);
int				*ini_ant_each(t_vec ways);
int				search_end(int *way);
int				next_room(t_ant *ant_info, t_vec *ant, int i);
void			ini_ant(t_vec *ant, int all_ants, t_vec tmp);
t_vec			dijkstra(t_rooms *rooms);
void			print_vec(t_vec *vec);
void			print_non_queue(t_vec *vec);
void			del_tab(char **tab);
void			del_ways(t_vec *vec);
void			del_vec_t_st(t_vec *vec);
void			del_vec_t_ant(t_vec *vec, int i);
void			del_tab_and_t_st(char **tab, t_vec *vec);
void			error(char *s);
void			print_ant(t_vec ways, char **tab, int ant, t_rooms *rooms);
char			**pars(char **tmp, t_mat *mat);
char			**make_matrice(t_vec*vec, int i, t_mat *mat, char **tab);
t_vec			algo(t_rooms *rooms);
#endif
