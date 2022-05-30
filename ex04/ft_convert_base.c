/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:27:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/30 13:34:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>






#include <stdio.h>

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
		if (s[i] == '-' || s[i] == '+')
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

// long	count_digit_by_base(char *n, long base)
// {

// }

long	get_num_by_base(char n, char *base)
{
	long	i;

	i = 0;
	while (base[i] && base[i] != n)
		++i;
	return (i);
}

long	ft_atoi_base(char *n, char *base)
{
	long	b;
	long	ret;
	long	i;
	long	len;
	long	sign;

	n = skip_space(n);
	n = skip_get_sign(n, &sign);
	len = ft_strlen_check(n);
	if (get_base(base, &b) == ERROR || len == ERROR)
		return (0);
	i = 0;
	ret = 0;
	printf("CC - %ld\n", b);
	while (i < len)
	{
		ret = (ret * b) + get_num_by_base(*n, base);
		printf("BB - %ld\n", ret);
		++n;
		++i;
	}
	return (ret * sign);
}


void	ft_itoa_base(long n, long base, char *base_str, char *ret)
{
	if (n / base)
	{
		ft_itoa_base(n / base, base, base_str, ret + 1);
		ft_itoa_base(n % base, base, base_str, ret + 1);
	}
	if (n < base)
		*ret = base_str[n - 1];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	tmp;
	long	b_to;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 1000);

	// if (get_base(base_from, &b_from) == ERROR || get_base(base_to, &b_to) == ERROR)
	// 	return (NULL);

	
	tmp = ft_atoi_base(nbr, base_from);
	printf("AA - %ld\n", tmp);
	get_base(base_to, &b_to);
	ft_itoa_base(tmp, b_to, base_to, ret);

	ret[1] = 0;
	return (ret);
}

int	main(void)
{
	char *n = "100";
	char *b_from = "01";
	// char *b_to = "0123456789";

	// printf("%s\n", ft_convert_base(n, b_from, b_to));
	printf("%ld\n", ft_atoi_base(n, b_from));
}