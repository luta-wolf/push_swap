/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_med.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:49 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:13 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	move_a_to_b_first(t_all *all)
// {
// 	int	i;
// 	int len;

// 	min_max_med_a(all);
// 	len = all->max - all->med + 1;
// 	i = all->size_a;
// 	while (i-- > 0)
// 	{
// 		if (all->stack_a->index <= all->med)
// 			pb(all);
// 		else
// 		{
// 			if (all->size_b == len)
// 				break ;
// 			else
// 				ra(all, 1);
// 		}
// 	}
// }

// void	move_a_to_b_first(t_all *all)
// {
// 	int	i;
// 	int len;

// 	min_max_med_a(all);
// 	len = all->max - all->med + 1;
// 	i = all->size_a;
// 	while (i-- > 0)
// 	{
// 		if (all->stack_a->index <= all->med)
// 		{
// 			pb(all);
// 			if (all->stack_b->index == all->min)
// 			{
// 				all->stack_b->flag = -1;
// 				rb(all, 1);
// 			}
// 		}
// 		else
// 		{
// 			if (all->size_b == len)
// 				break ;
// 			else
// 				ra(all, 1);
// 		}
// 	}
// 	rrb(all, 1);
// 	pa(all);
// 	ra(all, 1);
// }

void	move_a_to_b_first(t_all *all)
{
	int	i;
	int len;

	min_max_med_a(all);
	len = all->max - all->med + 1;
	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->index <= all->med)
		{
			pb(all);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				all->min++;
				rb(all, 1);
			}
		}
		else
		{
			if (all->size_b == len)
				break ;
			else
				ra(all, 1);
		}
	}
	while (all->stack_b->prev->flag == -1)
		rrb(all, 1);
	while (all->stack_b->flag == -1)
	{
		pa(all);
		ra(all, 1);
	}
}

void	min_max_med_a(t_all *all)
{
	int	i;
	int	min;
	int	max;

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
}

void	min_max_med_b(t_all *all)
{
	int	i;
	int	min;
	int	max;

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
	// all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
}
