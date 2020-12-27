/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:41:57 by htomohit          #+#    #+#             */
/*   Updated: 2020/10/27 23:48:48 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	res = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (sign < 0 && res > LLONG_MAX)
			return (0);
		if (sign > 0 && res > (unsigned long long)(-LLONG_MIN))
			return (-1);
	}
	return ((int)res * sign);
}
