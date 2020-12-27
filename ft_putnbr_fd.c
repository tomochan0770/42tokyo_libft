/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:25:31 by htomohit          #+#    #+#             */
/*   Updated: 2020/10/27 23:59:16 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fin_putnbr(int nb, int fd)
{
	char	c;

	c = nb + '0';
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
		}
		else
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
	}
	else if (n < 10)
	{
		fin_putnbr(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
