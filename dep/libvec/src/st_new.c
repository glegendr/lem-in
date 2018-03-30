/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:09:00 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:12:04 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_string	st_new(void)
{
	t_string string;

	string.vec.private_content = malloc(NB_ELEM_INI);
	string.vec.private_elem_nb = 0;
	string.vec.private_elem_size = 1;
	string.vec.private_elem_cap = NB_ELEM_INI;
	return (string);
}
