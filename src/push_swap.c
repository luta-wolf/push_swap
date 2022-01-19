/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/18 22:58:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(int argc, char **argv)
{
	t_all	*all;
	int i;

	all = init_struct(argc);
	sort(all, argc, argv);
	if (sort_true(all))
		free_stack(all);
	if (all->size_a < 6)
	{
		sort_five(all);
		exit(0);
	}
	move_a_to_b_first(all);
	//---------------------------------------------------
	// while (!sort_true(all) && all->size_b != 0)
	// {
	// 	printf("Hello World!\n");
	// 	break ;
	// }
	while (all->size_b != 0)
	{
		if (all->size_b < 4)
			sort_three_b(all);
		else if (all->size_b >= 4)
			move_b_to_a(all);
		if (all->size_b == 0)
			move_a_to_b(all);
	}
	i = sort_true(all);

	print_stacks(all);
	printf("sort(%d), size_b(%d)\n", i, all->size_b);
	printf("min %d, min_a %d\n", all->min, all->stack_a->prev->index + 1);



	free_stack(all);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_arg(argv);
		add_stack(argc, argv);
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
