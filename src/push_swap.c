/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/21 00:29:27 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(int argc, char **argv)
{
	t_all	*all;
	int i;

	all = init_struct(argc);
	add_to_stack(all, argc, argv);
	if (sort_true(all))
		free_stack(all);
	if (all->size_a < 6)
	{
		sort_five(all);
		free_stack(all);
	}
	move_a_to_b_first(all);
	//---------------------------------------------------
	while (!(sort_true(all) && all->size_b == 0))
	{
		if (all->size_b > 0 && all->size_b < 4)
			sort_three_b(all);
		else if (all->size_b >= 4)
			move_b_to_a(all);
		if (all->size_b == 0)
			move_a_to_b(all);
	}
	i = sort_true(all);


	// printf("sort(%d), size_b(%d)\n", i, all->size_b);
	// printf("min = %d", all->min);

	// print_stacks(all);
	free_stack(all);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		parsing(argv);
		sorting(argc, argv);
	}
	return (0);
}


/*
Парсинг
- Склеить строку по пробелам
- расплитовать по пробелам
- проверить что подаются только числа (атои)
- проверить числа на повторяемость

Сортировка:
1) написать функции:
- добавление аргументов в стек а (min_a = 1)
- сортирвки пузырьком/ вставкой/ выбором
- прописть каждому числу его индекс
- проверки что стек отсортирован
- команды push/swap/rotate/reverse
- сортировки 3-х и 5-ти чисел
- поиск медианы
- переброс в стек б все что меньше медианы
Запуск главного алгоритма
- переброс в стек а
- после сортировки всю память очищаем и выходим
*/
