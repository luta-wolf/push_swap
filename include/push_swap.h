/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/12 21:49:30 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // для printf (после удалить)
#include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
// colors
# define TURQUOISE 	"\033[36;1m"
# define END		"\033[0m"

typedef struct s_node // структура листа
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
}					t_all;

void	sort(t_all *all, int len, char **arr);

void	lstadd_back(t_node **stack_a, t_node *new);
t_node	*new_list(int num, int index);
void free_stack(t_all *all);

#endif
