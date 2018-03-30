/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:17:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:51:16 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_string	st_copy(t_string *string)
{
	t_string stringcpy;

	stringcpy.vec = v_copy(&string->vec);
	return (stringcpy);
}
