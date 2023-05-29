/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:38:05 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/10 10:55:15 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_int(int n, int fd)
{
	char	num;
	int		c;

	if (n <= 9)
	{
		num = n + 48;
		write(fd, &num, 1);
	}
	else
	{
		c = n / 10;
		ft_print_int(c, fd);
		num = (n % 10) + 48;
		write (fd, &num, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write (fd, "-", 1);
			write (fd, "2", 1);
			n += 2000000000;
			n *= -1;
		}
		else
		{
			write (fd, "-", 1);
			n *= -1;
		}
	}
	ft_print_int(n, fd);
}
