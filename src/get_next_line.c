/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:58:22 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/20 14:39:51 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_return_value(t_vec *vec, char **line, int r, int i)
{
	t_vec	vec2;
	void	*pos;

	if (i == 1)
	{
		vec2 = v_split(vec, r);
		pos = v_raw(&vec2);
		((char *)pos)[r] = 0;
		*line = pos;
		return (1);
	}
	vec2 = v_split(vec, v_size(vec) - 1);
	pos = v_raw(&vec2);
	((char *)pos)[v_size(&vec2)] = 0;
	*line = pos;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_vec	vec;
	char			s[BUFF_SIZE + 1];
	int				r;
	int				ret;
	void			*tmp;

	if (v_raw(&vec) == NULL)
		vec = v_new(sizeof(char));
	while ((ret = read(fd, s, BUFF_SIZE)) > 0 || v_size(&vec) != 0)
	{
		if (ret == -1)
			break ;
		r = 0;
		v_append_raw(&vec, s, ret);
		tmp = v_raw(&vec);
		while (r < v_size(&vec))
			if (((char *)tmp)[r++] == '\n')
				return (ft_return_value(&vec, line, r - 1, 1));
		if (ret == 0)
			return (ft_return_value(&vec, line, 0, 0));
	}
	if (ret == 0)
		return (0);
	return (-1);
}
