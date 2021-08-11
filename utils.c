/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 01:07:29 by awoods            #+#    #+#             */
/*   Updated: 2021/08/11 01:07:31 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int						znak;
	unsigned long long		result;

	result = 0;
	znak = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		znak = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > INT64_MAX && (znak == 1))
			return (-1);
		if (result > INT64_MAX && (znak == -1))
			return (-1);
		str++;
	}
	return ((int)result * znak);
}

static char	*ft_check(int	n, int	znak)
{
	char	*str;
	int		len;
	int		temp;

	temp = n;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp > 0)
	{
		temp = temp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + znak + 1));
	if (!str)
		return (NULL);
	str[len + znak] = '\0';
	while (len > 0)
	{
		str[len - 1 + znak] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		znak;

	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	znak = 0;
	if (n < 0)
	{
		znak = 1;
		n = -n;
	}
	str = ft_check(n, znak);
	if (!str)
		return (NULL);
	if (znak == 1)
		str[0] = '-';
	return (str);
}
