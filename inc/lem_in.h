/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:54:22 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/01 23:37:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "vector.h"

typedef struct	s_st
{
	char		*nom;
	int			x;
	int			y;
	int			fourmi;
	int			pos_mat;
	int			special;
}				t_st;

int				pars(t_vec *vec, char **tmp);
#endif
