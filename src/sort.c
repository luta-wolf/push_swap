/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:49 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/15 22:22:37 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_all *all)
{
	int i;

	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->index <= all->med)
			pb(all);
		else
			ra(all, 1);
	}
}

void	b_to_a(t_all *all)
{
	int i;
	int len_order;

	i = all->size_b;
	len_order = 0;
	while (i--)
	{
		if (all->stack_b->flag == all->order)
			len_order++;
	}
	min_max_med_b(all);

}

void	min_max_med_a(t_all *all)
{
	int i;
	int min;
	int max;

	if (all->size_a == 0)
		return ;
	i = all->size_a;
	min = all->stack_a->index;
	max = all->stack_a->index;
	while (i-- > 0)
	{
		if (min > all->stack_a->index)
			min = all->stack_a->index;
		if (max < all->stack_a->index)
			max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
	printf("Stack a: min %d ", all->min);
	printf("max %d ", all->max);
	printf("med %d\n", all->med);
}

void	min_max_med_b(t_all *all)
{
	int i;
	int min;
	int max;

	if (all->size_b == 0)
		return ;
	i = all->size_b;
	min = all->stack_b->index;
	max = all->stack_b->index;
	while (i-- > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
	printf("Stack b: min %d ", all->min);
	printf("max %d ", all->max);
	printf("med %d\n", all->med);
}
