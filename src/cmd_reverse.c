/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:01:02 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/15 14:03:51 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rra : reverse rotate a - сдвигает вниз все элементы стека a на 1.
			Последний элемент становится первым.
rrb : reverse rotate b - сдвинуть вниз все элементы стека b на 1.
			Последний элемент становится первым.
rrr : rra и rrb одновременно.*/

void	rra(t_all *all)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
}

void	rrb(t_all *all)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
}

void	rrr(t_all *all)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		rra(all);
		rrb(all);
	}
}
