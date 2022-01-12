/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:09:41 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/16 01:08:55 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mass;

	mass = (char *) malloc(count * size);
	if (mass == NULL)
		return (NULL);
	ft_bzero(mass, count * size);
	return (mass);
}
