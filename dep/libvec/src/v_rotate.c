/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:04:44 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/12 22:35:00 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void		v_rotate(t_vec *vec)
{
	void *tmp;
	void *tmp2;

	tmp2 = malloc((vec->private_elem_nb - 1) * vec->private_elem_size);
	tmp = malloc(vec->private_elem_size);
	ft_memcpy(tmp, v_get(vec, 0), vec->private_elem_size);
	ft_memcpy(tmp2, v_get(vec, 1), vec->private_elem_size *
			(vec->private_elem_nb - 1));
	free(vec->private_content);
	vec->private_content = malloc(vec->private_elem_cap *
			vec->private_elem_size);
	ft_memcpy(v_get(vec, 0), tmp2, (vec->private_elem_nb - 1)
			* vec->private_elem_size);
	ft_memcpy(v_get(vec, v_size(vec) - 1), tmp, vec->private_elem_size);
	free(tmp2);
	free(tmp);
}
