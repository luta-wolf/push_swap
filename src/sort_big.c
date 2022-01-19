/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:36:26 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/19 22:55:05 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_b_to_a(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		all->stack_b->flag = -1;
		pa(all);
		ra(all, 1);
		return (1);
	}
	else if (all->stack_a->index == min)
	{
		all->stack_a->flag = -1;
		ra(all, 1);
	}
	else if (all->stack_a->next->index == min)
	{
		all->stack_a->next->flag = -1;
		sa(all, 1);
		ra(all, 1);
	}
	return (0);
}

void	move_b_to_a(t_all *all)
{
	int	i;

	min_max_med_b(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}

// void	move_a_to_b(t_all *all)
// {
// 	int flag;

// 	flag = all->stack_a->flag;
// 	while (all->stack_a->flag == flag && flag != -1)
// 			pb(all);
// }

void	move_a_to_b(t_all *all)
{
	int	flag;
	int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			search_min_a_to_b(all);
		if (all->stack_a->index == min)
		{
			all->stack_a->flag = -1;
			ra(all, 1);
		}
		else
			pb(all);
	}
}

void	search_min_a_to_b(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		all->stack_b->flag = -1;
		pa(all);
		ra(all, 1);
	}
	else if (all->stack_b->next->index == min)
	{
		all->stack_b->next->flag = -1;
		sb(all, 1);
		pa(all);
		ra(all, 1);
	}
	else if (all->stack_b->prev->index == min)
	{
		all->stack_b->prev->flag = -1;
		rrb(all, 1);
		pa(all);
		ra(all, 1);
	}
	else if (all->stack_a->next->index == min)
	{
		all->stack_a->next->flag = -1;
		sa(all, 1);
		ra(all, 1);
	}
}
