/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:36:26 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/17 21:14:37 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_min_b(t_all *all)
{
	min_max_med_b(all);
	if (all->stack_b->index == all->min)
	{
		all->stack_b->flag = -1;
		pa(all);
		ra(all, 1);
	}
	else if (all->stack_b->next->index == all->min)
	{
		all->stack_b->next->flag = -1;
		sb(all, 1);
		pa(all);
		ra(all, 1);
	}
	else if (all->stack_b->prev->index == all->min)
	{
		all->stack_b->prev->flag = -1;
		rrb(all, 1);
		pa(all);
		ra(all, 1);
	}
}


void	move_b_to_a(t_all *all)
{
	int i;

	min_max_med_b(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (all->stack_b->index <= all->med)
		{
			all->stack_b->flag++;
			pa(all);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
		print_stacks(all);
	}
}
