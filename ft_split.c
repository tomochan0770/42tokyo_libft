/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 22:00:25 by htomohit          #+#    #+#             */
/*   Updated: 2020/11/01 11:56:17 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_str(char *s, char c)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (flag == 1 && s[i] == c)
			flag = 0;
		if (flag == 0 && s[i] != c)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int			sep_strlen(char *str, int idx, char c)
{
	int		len;

	len = 0;
	while (str[idx] != c && str[idx])
	{
		len++;
		idx++;
	}
	return (len);
}

static char			**all_free(char **res, int idx)
{
	while (idx >= 0)
	{
		free(res[idx]);
		idx--;
	}
	free(res);
	return (NULL);
}

static char			**create_str(char *s, char c, char **res)
{
	int		len;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = sep_strlen((char *)s, i, c);
			if (!(res[k] = malloc(sizeof(char) * (len + 1))))
				return (all_free(res, k - 1));
			j = 0;
			while (j < len)
				res[k][j++] = s[i++];
			res[k++][j] = '\0';
		}
		else
			i++;
	}
	res[k] = NULL;
	return (res);
}

char				**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	if (!(res = malloc(sizeof(char *) * (count_str((char *)s, c) + 1))))
		return (NULL);
	create_str((char *)s, c, res);
	return (res);
}
