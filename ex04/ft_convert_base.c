/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:27:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/30 13:55:13 by yrabby           ###   ########.fr       */
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

long	count_digit_by_base(long n, long base)
{
	long	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++ret;
	while (n)
	{
		n /= base;
		++ret;
	}
	return (ret);
}

long	get_num_by_base(char n, char *base)
{
	long	i;

	i = 0;
	while (base[i] && base[i] != n)
		++i;
	return (i);
}

long	ft_atoi_base(char *n, char *base_str, long base)
{
	long	ret;
	long	len;
	long	sign;

	n = skip_space(n);
	n = skip_get_sign(n, &sign);
	ret = 0;
	while (*n)
	{
		ret = (ret * base) + get_num_by_base(*n, base_str);
		++n;
	}
	return (ret * sign);
}


void	ft_itoa_base(long n, long base, char *base_str, char *ret)
{
	if (n / base)
	{
		ft_itoa_base(n / base, base, base_str, ret - 1);
		ft_itoa_base(n % base, base, base_str, ret);
	}
	if (n < base)
		*ret = base_str[n];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	tmp_nbr;
	long	b_to;
	long	b_from;
	long	digit;
	char	*ret;

	
	if (get_base(base_from, &b_from) == ERROR || get_base(base_to, &b_to) == ERROR)
		return (NULL);
		
	// Check nbr!
	// Check Neg
	
	tmp_nbr = ft_atoi_base(nbr, base_from, b_from);
	digit = count_digit_by_base(tmp_nbr, b_to);
	ret = (char *)malloc(sizeof(char) *  (digit + 1));
	if (!ret)
		return (NULL);
	
	ft_itoa_base(tmp_nbr, b_to, base_to, ret + digit - 1);

	ret[digit] = 0;
	return (ret);
}

int	main(void)
{
	char *n = "a";
	char *b_from = "0123456789abcdef";
	char *b_to = "01";
	char *ret;

	ret = ft_convert_base(n, b_from, b_to);
	printf("%s\n", ret);
	free(ret);
}