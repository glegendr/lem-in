/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:28:51 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:52:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		st_push(t_string *string, char elem)
{
	char *s;

	s = malloc(sizeof(char));
	s[0] = elem;
	v_push(&string->vec, s);
	free(s);
}
