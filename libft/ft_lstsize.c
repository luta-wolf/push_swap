/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:13:31 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/17 12:36:05 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*iterator;
	int		i;

	i = 0;
	iterator = lst;
	while (iterator != NULL)
	{
		iterator = iterator -> next;
		i++;
	}
	return (i);
}
