/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optima.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:57:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/22 16:51:56 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_to_b(t_all *all)
{
	int	a;
	int	b;
	int	c;

	if (all->size_b == 0)
		return ;
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->prev->index;
	if (b > a && b > c)
		rrb(all, 1);
	else if (a > b && a > c)
		rb(all, 1);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	if (a > b)
		sb(all, 1);
}

void	privet_norma(t_all *all, int flag)
{
	sort_three_a_to_b(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag != flag)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1)
		push_down(all);
}

void	sort_a_to_b_five(t_all *all, int flag, int min, int i)
{
	t_node	*tmp;

	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (all->stack_a->index == min)
			{
				push_down(all);
				min++;
			}
			else
				pb(all, 1);
			i--;
		}
		privet_norma(all, flag);
	}
}

void	privet_norma_2(t_all *all, int flag)
{
	sort_three_a_to_b(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
			all->stack_a->index +1 == all->stack_a->prev->index)
		push_down(all);
}

void	sort_b_to_a_five(t_all *all)
{
	int		flag;
	int		min;
	int		i;
	t_node	*tmp;

	i = all->size_b;
	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			push_down(all);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	privet_norma_2(all, flag);
}
