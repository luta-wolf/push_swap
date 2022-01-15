/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:16:22 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/14 21:27:19 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stacks(t_all *all)
// {
// 	int		i;

// 	ft_putstr_fd("\033[36;1m---- stack a ----\033[0m\n", 1);
// 	ft_putstr_fd("num\tindex\tflag\n", 1);
// 	i = -1;
// 	while (all->size_a > ++i)
// 	{
// 		ft_putnbr_fd(all->stack_a->num, 1);
// 		write(1, "\t", 1);
// 		ft_putnbr_fd(all->stack_a->index, 1);
// 		write(1, "\t", 1);
// 		ft_putnbr_fd(all->stack_a->flag, 1);
// 		all->stack_a = all->stack_a->next;
// 		write(1, "\n", 1);
// 	}
// 	write(1, "\033[36;1m---- stack b ----\033[0m\n", 30);
// 	write(1, "num\tindex\tflag\n", 15);
// 	i = -1;
// 	while (all->size_b > ++i)
// 	{
// 		ft_putnbr_fd(all->stack_b->num, 1);
// 		write(1, "\t", 1);
// 		ft_putnbr_fd(all->stack_b->index, 1);
// 		write(1, "\t", 1);
// 		ft_putnbr_fd(all->stack_b->flag, 1);
// 		all->stack_b = all->stack_b->next;
// 		write(1, "\n", 1);
// 	}
// 	write(1, "\033[36;1m-----------------\033[0m\n", 30);
// }

void print_stacks(t_all *all)
{
	int		i;

	ft_putstr_fd("\033[36;1m------ stack a -----|  \033[0m", 1);
	ft_putstr_fd("\033[36;1m|------ stack b -----|\033[0m\n", 1);
	ft_putstr_fd("num\tindex\tflag\tnum\tindex\tflag\n", 1);
	i = 0;
	while (all->size_a > i || all->size_b > i)
	{
		if (all->size_a > i)
			ft_putnbr_fd(all->stack_a->num, 1);
		write(1, "\t", 1);
		if (all->size_a > i)
			ft_putnbr_fd(all->stack_a->index, 1);
		write(1, "\t", 1);
		if (all->size_a > i)
			ft_putnbr_fd(all->stack_a->flag, 1);
		write(1, "\t", 1);
		if (all->size_a > i)
			all->stack_a = all->stack_a->next;
		if (all->size_b > i)
		{
		ft_putnbr_fd(all->stack_b->num, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(all->stack_b->index, 1);
		write(1, "\t", 1);
		ft_putnbr_fd(all->stack_b->flag, 1);
		all->stack_b = all->stack_b->next;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_putstr_fd("\033[36;1m--------------------|  \033[0m", 1);
	ft_putstr_fd("\033[36;1m|--------------------|\033[0m\n", 1);
}
