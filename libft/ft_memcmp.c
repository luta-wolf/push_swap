/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:16:11 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/11 17:14:08 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (n != i && ss1[i] == ss2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (ss1[i] - ss2[i]);
}
