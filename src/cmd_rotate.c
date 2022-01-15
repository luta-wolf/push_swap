/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:00:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/15 14:05:17 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ra : rotate a - сдвигает вверх все элементы стека a на 1.
			Первый элемент становится последним.
rb : rotate b - сдвинуть вверх все элементы стека b на 1.
			Первый элемент становится последним.
rr : ra и rb одновременно.*/

void	ra(t_all *all)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->next;
}

void	rb(t_all *all)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
}

void	rr(t_all *all)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		ra(all);
		rb(all);
	}
}
