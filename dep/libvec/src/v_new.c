/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:04:30 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/19 16:58:42 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec		v_new(int elem_size)
{
	t_vec vec;

	vec.private_content = malloc(elem_size * NB_ELEM_INI);
	vec.private_elem_nb = 0;
	vec.private_elem_size = elem_size;
	vec.private_elem_cap = NB_ELEM_INI;
	return (vec);
}
