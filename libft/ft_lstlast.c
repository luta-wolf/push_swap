/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:52:53 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/17 12:34:24 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iterator;

	iterator = lst;
	if (lst == NULL)
		return (NULL);
	while (iterator -> next != NULL)
		iterator = iterator -> next;
	return (iterator);
}
