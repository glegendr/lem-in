/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:35:43 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:52:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		st_push_first(t_string *string, char elem)
{
	char *s;

	s = malloc(sizeof(char));
	s[0] = elem;
	v_push_first(&string->vec, s);
	free(s);
}
