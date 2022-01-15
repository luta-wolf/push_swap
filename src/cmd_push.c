/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:40 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/15 14:09:42 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*pa : push a — взять первый элемент в верхней части b и поместить его в
				верхнюю часть a. Ничего не делать, если b пусто.
pb : push b — взять первый элемент в верхней части a и поместить его в
				верхнюю часть b. Ничего не делать, если a пусто.*/

void	push_b(t_all *all)
{
	t_node	*tmp;

	tmp = all->stack_a->next;
	all->stack_a->prev->next = all->stack_a->next;
	all->stack_a->next->prev = all->stack_a->prev;
	if (all->stack_b)
	{
		all->stack_a->prev = all->stack_b->prev;
		all->stack_a->next = all->stack_b;
		all->stack_b->prev->next = all->stack_a;
		all->stack_b->prev = all->stack_a;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_a->next = all->stack_b;
		all->stack_a->prev = all->stack_b;
	}
	all->stack_a = tmp;
}

void	push_a(t_all *all)
{
	t_node	*tmp;

	tmp = all->stack_b->next;
	all->stack_b->prev->next = all->stack_b->next;
	all->stack_b->next->prev = all->stack_b->prev;
	if (all->stack_a)
	{
		all->stack_b->prev = all->stack_a->prev;
		all->stack_b->next = all->stack_a;
		all->stack_a->prev->next = all->stack_b;
		all->stack_a->prev = all->stack_b;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->prev = all->stack_a;
	}
	all->stack_b = tmp;
}

void	pb(t_all *all)
{
	if (all->size_a == 0)
		return ;
	push_b(all);
	if (all->size_a == 1)
		all->stack_a = NULL;
	all->size_b++;
	all->size_a--;
}

void	pa(t_all *all)
{
	if (all->size_b == 0)
		return ;
	push_a(all);
	if (all->size_b == 1)
		all->stack_b = NULL;
	all->size_b--;
	all->size_a++;
}
