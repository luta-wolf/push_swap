/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:16:22 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/21 17:18:23 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	color(t_all *all)
{
	getchar();
	system("clear");
	ft_putstr_fd("\033[01;38;05;226;48;05;97m", 1);
	ft_putnbr_fd(all->size_a, 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[36;1m ---- stack a -----|  \033[0m", 1);
	ft_putstr_fd("\033[01;38;05;226;48;05;97m", 1);
	ft_putnbr_fd(all->size_b, 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[36;1m|------ stack b -----|\033[0m\n", 1);
	ft_putstr_fd("\033[01;38;05;226;48;05;97m", 1);
	ft_putstr_fd("num\tindex\tflag\tnum\tindex\tflag\033[0m\n", 1);
}

void	print_stacks(t_all *all, t_node *tmp_a, t_node	*tmp_b)
{
	int		i;

	color(all);
	i = 0;
	while (all->size_a > i || all->size_b > i)
	{
		if (all->size_a > i)
		{
			printf("%d\t%d\t%d\t", tmp_a->num, tmp_a->index, tmp_a->flag);
			tmp_a = tmp_a->next;
		}
		else
			printf("\t\t\t");
		if (all->size_b > i)
		{
			printf("%d\t%d\t%d", tmp_b->num, tmp_b->index, tmp_b->flag);
			tmp_b = tmp_b->next;
		}
		printf("\n");
		i++;
	}
	ft_putstr_fd("\033[36;1m--------------------|  \033[0m", 1);
	ft_putstr_fd("\033[36;1m|--------------------|\033[0m\n", 1);
}
