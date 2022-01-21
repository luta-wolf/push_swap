/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:44:03 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/21 16:06:31 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h> // для printf (после удалить)
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

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
	int				min_a;
}					t_all;

// push_swap.c
t_all	*parsing(char **argv);
void	sorting(t_all *all);

//	parser_check.c
char	**get_line(char **av);
void	repeated_double(char **av);
void	check_arg(char **arr);
void	free_arr(char **arr, int flag);
void	error(void);

// parser_init.c
t_all	*init_struct(char **arr);
t_node	*new_list(int num, int index);
void	lstadd_back(t_node **stack_a, t_node *new);
void	free_stack(t_all *all);
//---------------------------------------
// parser_add.c
void	add_to_stack(t_all *all, char **arr);
void	babble_sort(t_all *all, int *sort, int *not_sort, int len);
void	create_stack(t_all *all, int *sort, int *not_sort, int len);

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

// sort_big.c
int		search_min_b_to_a(t_all *all);
void	move_b_to_a(t_all *all);
void	move_a_to_b(t_all *all);
void	search_min_a_to_b(t_all *all);
void	push_down(t_all *all);

// sort_med.c
void	move_a_to_b_first(t_all *all);
void	min_max_med_a(t_all *all);
void	min_max_med_b(t_all *all);
void	move_down(t_all *all);

// ps_print.c - перед сдачей удалить
void	print_stacks(t_all *all);

#endif
