/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:45:37 by htomohit          #+#    #+#             */
/*   Updated: 2020/10/21 16:25:03 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1 + i);
	while (ft_strchr(set, s1[j + i]) && j > 0)
		j--;
	if (j == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j + 1));
}
