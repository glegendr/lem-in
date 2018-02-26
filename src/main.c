/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 07:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/26 22:59:43 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "matrice.h"

int		main(void)
{
	char *s;
	int i;
	t_vec vec;

	i = 0;
	vec = v_new(sizeof(char));
	while (get_next_line(0, &s))
	{
		v_append_raw(&vec, s, ft_strlen(s));
		v_push(&vec ,"\n");
		free(s);
	}
	while (((char *)v_get(&vec, i))[0] != '#')
		++i;
}
