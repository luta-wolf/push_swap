/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:40 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/14 18:53:25 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*pa : push a — взять первый элемент в верхней части b и поместить его в верхнюю часть a.
			Ничего не делать, если b пусто.
pb : push b — взять первый элемент в верхней части a и поместить его в верхнюю часть b.
			Ничего не делать, если a пусто.*/

void	pb(t_all *stack_all)
{
	if (stack_all->size_a == 0)
		return ;
	t_node	*tmp;

	tmp = stack_all->stack_a->next;
	stack_all->stack_a->prev->next = stack_all->stack_a->next;
	stack_all->stack_a->next->prev = stack_all->stack_a->prev;

	if (stack_all->stack_b == NULL)
	{
		stack_all->stack_b = stack_all->stack_a;
		stack_all->stack_a->next = stack_all->stack_b;
		stack_all->stack_a->prev = stack_all->stack_b;
	}
	else // (stack_all->stack_b)
	{
		stack_all->stack_a->prev = stack_all->stack_b->prev;
		stack_all->stack_a->next = stack_all->stack_b;
		stack_all->stack_b->prev->next = stack_all->stack_a;
		stack_all->stack_b->prev = stack_all->stack_a;
		stack_all->stack_b = stack_all->stack_a;
	}

	stack_all->stack_a = tmp;
	stack_all->size_b++;
	stack_all->size_a--;
}


void pa(t_all *stack_all)
{
	if (stack_all->size_b == 0)
		return ;
	t_node	*tmp;

	tmp = stack_all->stack_b->next;
	stack_all->stack_b->prev->next = stack_all->stack_b->next;
	stack_all->stack_b->next->prev = stack_all->stack_b->prev;

	if (stack_all->stack_a)
	{
		stack_all->stack_b->prev = stack_all->stack_a->prev;
		stack_all->stack_b->next = stack_all->stack_a;
		stack_all->stack_a->prev->next =stack_all->stack_b;
		stack_all->stack_a->prev = stack_all->stack_b;
		stack_all->stack_a = stack_all->stack_b;
	}
	else
	{
		stack_all->stack_a = stack_all->stack_b;
		stack_all->stack_a->next = stack_all->stack_a;
		stack_all->stack_a->prev = stack_all->stack_a;
	}
	stack_all->stack_b = tmp;
	stack_all->size_b--;
	stack_all->size_a++;
}

