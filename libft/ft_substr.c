/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:06:11 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/05 10:21:39 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	size_s;
	size_t	i;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start > size_s)
		len = 0;
	if (len > (size_s - start))
		len = size_s - start;
	array = (char *) ft_calloc((len + 1), sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = s[i + start];
		i++;
	}
	array[i] = '\0';
	return (array);
}
