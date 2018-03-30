/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_append_raw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:12:37 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:16:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		st_append_raw(t_string *string, char *elem, int nb)
{
	v_append_raw(string->vec, elem, nb);
}
