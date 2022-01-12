/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:09:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/12 21:20:32 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_all *all, int len, char **arr)
{
	int *arr_not_sort;
	int *arr_sort;
	int i;
	int j;
	int tmp;
	int count;
	int num;

	arr_not_sort = malloc(sizeof(int) * (len -1));
	arr_sort = malloc(sizeof(int) * (len -1));
	i = 0;
	while (i < len - 1)
	{
		num = ft_atoi(arr[i + 1]);
		arr_not_sort[i] = num;
		arr_sort[i] = num;
		i++;
	}
	i = 0;
	while (i < len - 1)
		printf("%d ", arr_not_sort[i++]);
	printf("Начальный массив\n");
	i = 0;
	count = 0;
	while(i < (len - 1))
	{
		j = 0;
		while (j < (len -2 -i))
		{
			if(arr_sort[j] > arr_sort[j + 1])
				{
					tmp = arr_sort[j+1];
					arr_sort[j+1] = arr_sort[j];
					arr_sort[j] = tmp;
					count++;
				}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (len - 1))
	{
		printf("%d ", arr_sort[i]);
		i++;
	}
	printf("Массив отсортирован\nИтераций %d\n", count);

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr_not_sort[i] == arr_sort[j])
				lstadd_back(&all->stack_a, new_list(arr_not_sort[i], j + 1));
				// printf("%d\t[%d]\n", arr_not_sort[i], j);
			j++;
		}
		i++;
	}
	free(arr_not_sort);
	free(arr_sort);
}
