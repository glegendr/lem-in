/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:29:47 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/23 12:59:19 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_recursive_factorialvdeux(int nb, int i)
{
	i = i * nb;
	if (nb > 1)
	{
		nb = nb - 1;
		return (ft_recursive_factorialvdeux(nb, i));
	}
	return (i);
}

int				ft_recursive_factorial(int nb)
{
	int i;

	i = 1;
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_factorialvdeux(nb, i));
}
