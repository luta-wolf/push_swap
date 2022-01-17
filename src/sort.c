/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:49 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/17 15:39:51 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_true(t_all *all)
{
	int		i;
	t_node	*head;

	head = all->stack_a;
	i = all->size_a - 1;
	while (i-- > 0)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_three_a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_a->index;
	b = all->stack_a->next->index;
	c = all->stack_a->prev->index;
	if (b > a && b > c)
		rra(all, 1);
	else if (a > b && a > c)
		ra(all, 1);
	a = all->stack_a->index;
	b = all->stack_a->next->index;
	if (a > b)
		sa(all, 1);
}

int	short_cut(t_all *all)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = all->stack_a;
	i = 0;
	while (++i)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->next;
	}
	tmp = all->stack_a;
	j = 0;
	while (++j)
	{
		if (tmp->index == all->min)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	sort_five(t_all *all)
{
	while (all->size_a > 3)
	{
		min_max_med_a(all);
		if (all->stack_a->index == all->min)
		{
			pb(all);
			continue;
		}
		if (short_cut(all))
			ra(all, 1);
		else
			rra(all, 1);
	}
	sort_three_a(all);
	pa(all);
	pa(all);
}

void	a_to_b(t_all *all)
{
	int	i;

	i = all->size_a;
	while (i-- > 0)
	{
		printf("num = %d ind = [%d]\n", all->stack_a->num, all->stack_a->index);
		if (all->stack_a->index <= all->med)
			pb(all);
		else
			ra(all, 1);
		print_stacks(all);
	}
}

void	b_to_a(t_all *all)
{
	int	i;
	int	len_order;

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
	// printf("Stack a: min %d ", all->min);
	// printf("max %d ", all->max);
	// printf("med %d\n", all->med);
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
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
	// printf("Stack b: min %d ", all->min);
	// printf("max %d ", all->max);
	// printf("med %d\n", all->med);
}
