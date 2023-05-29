/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:56:33 by salvarad          #+#    #+#             */
/*   Updated: 2022/09/22 12:09:14 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
	{
		return (src_size + dstsize);
	}
	else
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - dst_size -1))
		{
			dst[dst_size + i] = src[i];
			i++;
		}
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
