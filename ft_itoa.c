/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:14:07 by htomohit          #+#    #+#             */
/*   Updated: 2020/10/21 11:29:42 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_num(int n)
{
	int		count;
	long	i;

	count = 0;
	i = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long	num;
	int		size;
	char	*res;

	num = (long)n;
	size = count_num(num);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	res[size] = '\0';
	while (size > 0 && num > 0)
	{
		res[--size] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
