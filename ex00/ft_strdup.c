/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:12:53 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/29 16:30:32 by yrabby           ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	while (src[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*ret;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, src, size + 1);
	return (ret);
}
