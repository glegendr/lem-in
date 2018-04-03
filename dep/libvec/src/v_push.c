/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:16:12 by glegendr          #+#    #+#             */
/*   Updated: 2018/04/03 16:32:32 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void		v_push(t_vec *vec, void *elem)
{
	if (vec->private_elem_cap <= vec->private_elem_nb)
	{
		if ((vec->private_content = ft_realloc(vec->private_content,
						vec->private_elem_cap * vec->private_elem_size,
						(NB_ELEM_INI + vec->private_elem_cap)
						* vec->private_elem_size)) == NULL)
			return ;
		vec->private_elem_cap += NB_ELEM_INI;
	}
	ft_memcpy(v_get(vec, vec->private_elem_nb), elem, vec->private_elem_size);
	++vec->private_elem_nb;
}
