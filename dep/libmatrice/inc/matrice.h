/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:13:28 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/06 17:16:51 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H
# include <stdlib.h>

typedef struct	s_mat
{
	int			*private_content;
	int			private_line_size;
}				t_mat;

void			ft_putnbr_fd(int i, int fd);
void			mat_print(t_mat *mat, int fd);
void			mat_del(t_mat *mat);
void			mat_set(t_mat *mat, int y, int x, int content);
int				mat_get(t_mat *mat, int y, int x);
int				mat_size(t_mat *mat);
t_mat			mat_new(int line_size);
#endif
