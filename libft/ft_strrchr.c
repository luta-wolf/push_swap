/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:37:48 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/14 11:26:52 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *)s + ft_strlen((char *)s);
	while (*pointer != (unsigned char)c)
	{
		if (pointer == (char *)s)
			return (NULL);
		pointer--;
	}
	return (pointer);
}
