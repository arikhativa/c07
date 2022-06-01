/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:27:55 by yrabby            #+#    #+#             */
/*   Updated: 2022/06/01 12:51:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR -1
#define SUCCESS 0

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

char	*skip_space(char *s)
{
	while (is_space(*s))
		++s;
	return (s);
}

char	*skip_get_sign(char *s, long *sign)
{
	*sign = 1;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		++s;
	}
	return (s);
}

long	ft_strlen_check(char *s)
{
	long	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+' || s[i] < 33 || s[i] > 126)
			return (ERROR);
		++i;
	}
	return (i);
}

int	get_base(char *s, long *res)
{
	long	i;
	long	j;

	i = 0;
	*res = ft_strlen_check(s);
	if (*res <= 1 || *res == ERROR)
		return (ERROR);
	while (i < *res)
	{
		j = i + 1;
		while (j < *res)
		{
			if (s[i] == s[j])
				return (ERROR);
			++j;
		}
		++i;
	}
	return (SUCCESS);
}
