/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:09:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/21 15:38:32 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_all *all, char **arr)
{
	int	*not_sort;
	int	*sort;
	int	i;
	int	num;
	int	len;

	len = 0;
	i = -1;
	while (arr[++i])
		len++;
	not_sort = malloc(sizeof(int) * (len));
	sort = malloc(sizeof(int) * (len));
	i = 0;
	while (i < len)
	{
		num = ft_atoi(arr[i]);
		not_sort[i] = num;
		sort[i] = num;
		i++;
	}
	babble_sort(all, sort, not_sort, len);
}

void	babble_sort(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
				count++;
			}
			j++;
		}
		i++;
	}
	create_stack(all, sort, not_sort, len);
}

void	create_stack(t_all *all, int *sort, int *not_sort, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
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

// void	add_to_stack(t_all *all, char **arr)
// {
// 	int	*not_sort;
// 	int	*sort;
// 	int	i;
// 	int	j;
// 	int	tmp;
// 	int	count;
// 	int	num;
// 	int len = 0;

// 	i = -1;
// 	while (arr[++i])
// 		len++;
// 	not_sort = malloc(sizeof(int) * (len));
// 	sort = malloc(sizeof(int) * (len));
// 	i = 0;
// 	while (i < len)
// 	{
// 		num = ft_atoi(arr[i]);
// 		not_sort[i] = num;
// 		sort[i] = num;
// 		i++;
// 	}
// 	// i = -1;
// 	// while (++i < len)
// 	// 	printf("%d ", not_sort[i]);
// 	// printf("Начальный массив\n");
// 	i = 0;
// 	count = 0;
// 	while(i < len)
// 	{
// 		j = 0;
// 		while (j < (len -1 -i))
// 		{
// 			if(sort[j] > sort[j + 1])
// 				{
// 					tmp = sort[j+1];
// 					sort[j+1] = sort[j];
// 					sort[j] = tmp;
// 					count++;
// 				}
// 			j++;
// 		}
// 		i++;
// 	}
// 	// i = 0;
// 	// while (i < len)
// 	// {
// 	// 	printf("%d ", sort[i]);
// 	// 	i++;
// 	// }
// 	// printf("Массив отсортирован\nИтераций %d\n", count);

// 	i = 0;
// 	while (i < len)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if (not_sort[i] == sort[j])
// 			{
// 				lstadd_back(&all->stack_a, new_list(not_sort[i], j + 1));
// 				j++;
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// 	// i = -1;
// 	// while(++i < all->size_a)
// 	// {
// 	// 	printf("i = %d, (%d)\n", i, all->stack_a->num);
// 	// 	all->stack_a = all->stack_a->next;
// 	// }
// 	free(not_sort);
// 	free(sort);
// }
