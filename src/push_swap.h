/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/18 13:34:36 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // для printf (после удалить)
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
// colors
# define TURQUOISE 	"\033[36;1m"
# define END		"\033[0m"
// структура листа
typedef struct s_node
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
	int				min;
	int				med;
	int				max;
	int				order;
}					t_all;

// init.c
t_all	*init_struct(int argc);
t_node	*new_list(int num, int index);
void	lstadd_back(t_node **stack_a, t_node *new);
void	free_stack(t_all *all);

// cmd_push.c
void	pb(t_all *all);
void	pa(t_all *all);
void	push_b(t_all *all);
void	push_a(t_all *all);

// cmd_swap.c
void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all);

// cmd_rotate.c
void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all);

// cmd_reverse.c
void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all);

// sort_min.c
int		sort_true(t_all *all);
void	sort_three_a(t_all *all);
void	sort_three_b(t_all *all);
void	sort_five(t_all *all);
int		short_cut(t_all *all);
//---------------------------------------
// sort_big.c
void	search_min_b(t_all *all);
void	move_b_to_a(t_all *all);
void	move_a_to_b(t_all *all);

// min_max_med.c
void	move_a_to_b_first(t_all *all);
void	min_max_med_a(t_all *all);
void	min_max_med_b(t_all *all);
void	min_b(t_all *all);

// ps_print.c - перед сдачей удалить
void	print_stacks(t_all *all);

// sort_babble.c
void	sort(t_all *all, int len, char **arr);
//	parser.c
void	check_arg(char **av);
void	repeated_double(char **av);

// ps_error.c
void	error(void);

#endif