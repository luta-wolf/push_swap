/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_babble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:09:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/20 15:13:54 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_all *all, int len, char **arr)
{
	int	*not_sort;
	int	*sort;
	int	i;
	int	j;
	int	tmp;
	int	count;
	int	num;

	not_sort = malloc(sizeof(int) * (len -1));
	sort = malloc(sizeof(int) * (len -1));
	i = 0;
	while (i < len - 1)
	{
		num = ft_atoi(arr[i + 1]);
		not_sort[i] = num;
		sort[i] = num;
		i++;
	}
	i = 0;
	// while (i < len - 1)
	// 	printf("%d ", not_sort[i++]);
	// printf("Начальный массив\n");
	i = 0;
	count = 0;
	while(i < (len - 1))
	{
		j = 0;
		while (j < (len -2 -i))
		{
			if(sort[j] > sort[j + 1])
				{
					tmp = sort[j+1];
					sort[j+1] = sort[j];
					sort[j] = tmp;
					count++;
				}
			j++;
		}
		i++;
	}
	i = 0;
	// while (i < (len - 1))
	// {
	// 	printf("%d ", sort[i]);
	// 	i++;
	// }
	// printf("Массив отсортирован\nИтераций %d\n", count);

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (not_sort[i] == sort[j])
			{
				lstadd_back(&all->stack_a, new_list(not_sort[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(not_sort);
	free(sort);
}
