/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:02:00 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/17 12:35:33 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mem;

	mem = malloc(sizeof(t_list) * 1);
	if (mem == NULL)
		return (NULL);
	mem -> content = content;
	mem -> next = NULL;
	return (mem);
}
