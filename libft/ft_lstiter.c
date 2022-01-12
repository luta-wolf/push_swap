/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:11:48 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/17 12:33:43 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iterator;

	if (lst == NULL)
		return ;
	iterator = lst;
	while (iterator != NULL)
	{
		f(iterator -> content);
		iterator = iterator -> next;
	}
}
