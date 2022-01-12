/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/11 20:37:03 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}


void	check_arg(char **av)
{
	int		i;

	i = 1;
	while(av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
}

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if(list == NULL)
		return (NULL);
	list->num = num;
	list->flag = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	lstadd_back(t_node **stack_a, t_node *new)
{
	t_node	*begin;

	if(new == NULL)
		return ;
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = new;
			new->prev = begin->prev;
			new->next = begin;
			begin->prev = new;
		}
		else
		{
			begin->prev = new;
			begin->next = new;
			new->prev = begin;
			new->next = begin;
		}
	}
	else
		*stack_a = new;
	return ;
}

void add_stack(int argc, char **argv)
{
	t_all	*all;
	int i;

	all = malloc(sizeof(t_all));
	if(all == NULL)
		return ;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = argc - 1;
	all->size_b = 0;

	i = 1;
	while (argv[i])
	{
		int num = ft_atoi(argv[i]);
		lstadd_back(&all->stack_a, new_list(num, 0));
		// printf("- %d\n", num);
		i++;
	}
	write(1, "\n\033[1;32m----- *** -----\033[0m\n\n", 30);
	write(1, "\033[36;1m--- stack a ---\033[0m\n", 28);
	i = -1;
	while (all->size_a > ++i)
	{
		ft_putnbr_fd(all->stack_a->num, 1);
		all->stack_a = all->stack_a->next;
		write(1, "\n", 1);
	}
	write(1, "---------------\n\n", 17);
}

int	main(int argc, char **argv)
{
	if(argc > 1)
	{
		check_arg(argv);
		add_stack(argc, argv);
	}
	return 0;
}





/*
Парсинг
- Склеить строку по пробелам
- расплитовать по пробелам
- проверить что подаются только числа (атои)
- проверить числа на повторяемость

Сортировка
- отдельно отсортировать стек А и узнать медиану (число.
индекс которого находится по середине стека)
- кидать в стек В все что больше по значению медианного числа вверх
и все что меньше вниз
- В стеке А оставть 3 числа и отсортировать их
- из стека В кидать числа в стек А на их место с учетом нименьших затрат



1) написать функции:
- добавление в стек
-
*/
