/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:50:02 by htomohit          #+#    #+#             */
/*   Updated: 2020/10/21 16:21:17 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s);
	while (n + 1 > 0)
	{
		if (*(unsigned char *)(s + n) == (unsigned char)c)
			return ((char *)(s + n));
		n--;
	}
	return (NULL);
}
