/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:35:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/20 22:52:51 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	print_vec(t_vec *vec)
{
	int i;
	int y;
	t_vec tmp;

	i = 0;
	while (i < v_size(vec))
	{
		y = 0;
		tmp = *(t_vec *)v_get(vec, i);
		++i;
		while (y < v_size(&tmp))
			printf("%i ", *(int *)v_get(&tmp, y++));
		//while (y < v_size(&tmp))
		//	printf("%i ", *(int *)v_get(&tmp, y++));
		//printf("%p\n", tmp.private_content);
		printf("\n");
	}
}

void	print_non_queue(t_vec *vec)
{
	int i;

	i = 0;
	while (i < v_size(vec))
	{
		printf("%i ", *(int *)v_get(vec, i));
		i++;
	}
}
