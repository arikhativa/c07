/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:04:25 by yrabby            #+#    #+#             */
/*   Updated: 2022/06/01 11:51:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	count_word(char *s, char *sep, unsigned int sep_len)
{
	int	i;

	i = 0;
	while (ft_strncmp(s, sep, sep_len) == 0)
		s = s + sep_len;
	while (*s)
	{
		++i;
		while (*s && ft_strncmp(s, sep, sep_len) != 0)
			++s;
		while (ft_strncmp(s, sep, sep_len) == 0)
			s = s + sep_len;
	}
	return (i);
}

char	*create_str(char *s, char *sep, unsigned int sep_len, char **ret)
{
	int		i;
	char	*new_str;

	i = 0;
	while (s[i] && ft_strncmp(&(s[i]), sep, sep_len) != 0)
		++i;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	*ret = new_str;
	while (*s && ft_strncmp(s, sep, sep_len) != 0)
	{
		*new_str = *s;
		++s;
		++new_str;
	}
	*new_str = 0;
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	unsigned int	sep_len;
	int				c;
	int				i;
	char			**ret;

	sep_len = 0;
	while (charset[sep_len])
		++sep_len;
	c = count_word(str, charset, sep_len);
	ret = (char **)malloc(sizeof(char *) * (c + 1));
	if (!ret)
		return (NULL);
	ret[c] = NULL;
	i = -1;
	while (ft_strncmp(str, charset, sep_len) == 0)
		str = str + sep_len;
	while (++i < c)
	{
		str = create_str(str, charset, sep_len, &(ret[i]));
		if (ret[i] == NULL)
			return (ret);
		while (ft_strncmp(str, charset, sep_len) == 0)
			str = str + sep_len;
	}
	return (ret);
}
