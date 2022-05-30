/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:25:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/30 12:25:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	get_size_to_malloc(int size, char **strs, int size_of_sep)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c += ft_strlen(strs[i]);
		++i;
	}
	return (c + (size * size_of_sep) + 1);
}

char	*ft_strcpy_no_null(char *d, char *s)
{
	while (*s)
	{
		*d = *s;
		++s;
		++d;
	}
	return (d);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ret;
	char	*runner;

	ret = (char *)malloc(sizeof(char) * get_size_to_malloc(size, strs, ft_strlen(sep)));
	if (!ret)
		return (NULL);
	runner = ret;
	if (size)
		runner = ft_strcpy_no_null(runner, strs[0]);
	i = 1;
	while (i < size)
	{
		runner = ft_strcpy_no_null(runner, sep);
		runner = ft_strcpy_no_null(runner, strs[i]);
		++i;
	}
	*runner = 0;
	return (ret);
}
