/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:24:10 by salvarad          #+#    #+#             */
/*   Updated: 2022/09/29 10:49:52 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (((const char *) s1)[i] == ((const char *) s2)[i] && i < (n - 1))
	{
		i++;
	}
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
