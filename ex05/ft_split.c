/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:04:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/30 16:45:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>






#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2 || n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && i < n)
	{
		++s1;
		++s2;
		++i;
	}
	if (i == n)
		return (0);
	return (*s1 - *s2);
}

int	count_word(char *s, char* sep, unsigned int sep_len)
{
	int	i;

	i = 0;
	while (ft_strncmp(s, sep, sep_len) == 0)
		s = s + sep_len;
	if (*s)
		++i;
	while (*s)
	{
		while (*s && *s != *sep)
		{
			++s;
		}
		if (ft_strncmp(s, sep, sep_len) == 0)
		{
			s = s + sep_len;
			++i; // not true
		}
		else if (*s)
			++s;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	unsigned int	sep_len;
	int				c;
	char			*ret;

	sep_len = 0;
	while (charset[sep_len])
		++sep_len;
	c = count_word(str, charset, sep_len);
	ret = (char *)malloc(sizeof(char) * c + 1);
	if (!ret)
		return (NULL);
	

	return (ret);
}

int	main(void)
{
	ft_split("----------------", "--");
}