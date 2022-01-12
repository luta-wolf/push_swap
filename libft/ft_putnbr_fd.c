/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:39:19 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/15 19:10:29 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Печать	символов*/
void	ft_putchar(char a, int fd)
{
	write (fd, &a, 1);
}

/*Печать цифр*/
void	ft_put_small_int(int a, int fd)
{
	int	b;

	b = a + '0';
	write (fd, &b, 1);
}

/*Рекурсия*/
void	ft_recursion(int nb, int fd)
{
	int	j;

	j = nb % 10;
	nb = nb / 10;
	if (nb >= 10)
		ft_recursion(nb, fd);
	else
		if (nb != 0)
			ft_put_small_int(nb, fd);
	ft_put_small_int(j, fd);
}

/*Проверка условий*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n > 0)
		ft_recursion(n, fd);
	else if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
		ft_recursion(n, fd);
	}
	else
		ft_putchar('0', fd);
}
