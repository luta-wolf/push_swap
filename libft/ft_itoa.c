/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:57:17 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/15 15:10:48 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_nbr(int n)
{
	int		len;
	long	i;

	i = (long)n;
	if (n < 0)
		i = (long)n * -1;
	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else if (n == 0)
		return (1);
	else
		return (len + 1);
}

void	record_str(long n, int len, char	*str)
{
	str[len] = '\0';
	while (len != 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	len = size_nbr(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n >= 0)
		record_str(n, len, str);
	else
	{
		i = (long)n * -1;
		record_str(i, len, str);
		str[0] = '-';
	}
	return (str);
}
