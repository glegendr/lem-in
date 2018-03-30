/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:52:51 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/28 23:55:23 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		v_push_first(t_vec *vec, void *elem)
{
	int i;

	i = vec->private_elem_nb;
	if (vec->private_elem_cap <= vec->private_elem_nb)
	{
		if ((vec->private_content = ft_realloc(vec->private_content,
						vec->private_elem_cap * vec->private_elem_size,
						(NB_ELEM_INI + vec->private_elem_cap)
						* vec->private_elem_size)) == NULL)
			return ;
		vec->private_elem_cap += NB_ELEM_INI * vec->private_elem_size;
	}
	while (i > 0)
	{
		ft_memcpy(v_get(vec, i), v_get(vec, i - 1), vec->private_elem_size);
		--i;
	}
	ft_memcpy(v_get(vec, i), elem, vec->private_elem_size);
	++vec->private_elem_nb;
}
