/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:20:47 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/06 11:38:47 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_size_array(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n += 2000000000;
			size++;
		}
		n *= -1;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

int	ft_conv_neg(int n)
{
	if (n == -2147483648)
		n += 2000000000;
	n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		size_array;

	size_array = ft_size_array(n);
	array = (char *) ft_calloc((size_array + 1), sizeof(char));
	if (!array)
		return (NULL);
	array[size_array] = '\0';
	if (n < 0)
	{
		array[0] = '-';
		if (n == -2147483648)
			array[1] = '2';
		n = ft_conv_neg(n);
	}
	while (n > 9)
	{
		array[size_array - 1] = (n % 10) + 48;
		n = n / 10;
		size_array--;
	}
	array[size_array - 1] = n + 48;
	return (array);
}
