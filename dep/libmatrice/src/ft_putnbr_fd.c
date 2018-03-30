/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:13:27 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/06 17:15:53 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				i;

	nb = n;
	if (nb > 2147483648 || n < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		i = nb + '0';
		write(fd, &i, 1);
	}
}
