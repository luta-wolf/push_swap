/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:48:41 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/14 13:06:31 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*mem;
	char	*str;

	str = (char *)s1;
	len = ft_strlen((char *)s1);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
