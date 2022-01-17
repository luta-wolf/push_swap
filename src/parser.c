/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:06:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/16 21:10:54 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeated_double(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error();
			j++;
		}
		i++;
	}
}

void	check_arg(char **av)
{
	repeated_double(av);
}
