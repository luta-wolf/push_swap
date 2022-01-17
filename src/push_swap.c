/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/17 15:22:41 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_arg(char **av)
// {
// 	int		i;
// 	int		j;

// 	i = 1;
// 	while (av[i])
// 	{
// 		j = i + 1;
// 		while (av[j])
// 		{
// 			if (ft_atoi(av[i]) == ft_atoi(av[j]))
// 				error();
// 			j++;
// 		}
// 		i++;
// 	}
// }

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (list == NULL)
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

	if (new == NULL)
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

void	add_stack(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (all == NULL)
		return ;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = argc - 1;
	all->size_b = 0;
	all->order = 0;
	sort(all, argc, argv);
	if (sort_true(all))
	{
		printf("Sort\n");
		free_stack(all);
	}
	// sort_three_a(all);
	// short_cut(all);
	sort_five(all);


	// printf("num = %d ind = [%d]", all->stack_a->num, all->stack_a->index);
	// print_stacks(all);
	// pb(all);
	// print_stacks(all);
	// pb(all);
	// print_stacks(all);
	// min_max_med_a(all);
	// min_max_med_b(all);
	// a_to_b(all);
	// min_max_med_a(all);
	// min_max_med_b(all);


	print_stacks(all);

	free_stack(all);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_arg(argv);
		add_stack(argc, argv);
		// sort(argc, argv);
	}
	return (0);
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


Сортировка:
1) написать функции:
- добавление в стек
- отсортировать пузырьком/ вставкой/ выбором
- проверить стек на то отсортирован ли он, тогда чистим память и выходим
- запускаем главный алгоритм
- (прописываю функции push/swap)
- после сортировки всю память очищаем и выходим
*/
