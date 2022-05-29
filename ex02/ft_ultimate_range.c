/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:56:11 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/29 18:22:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define ERROR -1

int	ft_ultimate_range(int **range, int min, int max)
{
	long	size;
	int		i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = (long)max - (long)min;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == NULL)
		return (ERROR);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min;
		++i;
		++min;
	}
	return ((int)size);
}
