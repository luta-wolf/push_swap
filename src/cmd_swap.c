/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:06:39 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/15 18:37:56 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa : swap a — поменять местами первые 2 элемента в верхней части стека a.
			Ничего не делать, если есть только один элемент или его нет).
sb : swap b — поменять местами первые 2 элемента в верхней части стека b.
			Ничего не делать, если есть только один элемент или его нет).
ss : sa и sb одновременно.*/

void	sa(t_all *all, int flag)
{
	int	tmp;

	if (all->size_a < 2)
		return ;
	tmp = all->stack_a->num;
	all->stack_a->num = all->stack_a->next->num;
	all->stack_a->next->num = tmp;
	tmp = all->stack_a->index;
	all->stack_a->index = all->stack_a->next->index;
	all->stack_a->next->index = tmp;
	tmp = all->stack_a->flag;
	all->stack_a->flag = all->stack_a->next->flag;
	all->stack_a->next->flag = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_all *all, int flag)
{
	int	tmp;

	if (all->size_b < 2)
		return ;
	tmp = all->stack_b->num;
	all->stack_b->num = all->stack_b->next->num;
	all->stack_b->next->num = tmp;
	tmp = all->stack_b->index;
	all->stack_b->index = all->stack_b->next->index;
	all->stack_b->next->index = tmp;
	tmp = all->stack_b->flag;
	all->stack_b->flag = all->stack_b->next->flag;
	all->stack_b->next->flag = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_all *all)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		sa(all, 0);
		sb(all, 0);
		write(1, "ss\n", 3);
	}
}
