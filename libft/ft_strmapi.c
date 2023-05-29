/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:01:15 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/10 12:24:17 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	size_array;
	size_t	i;

	size_array = ft_strlen(s);
	array = (char *) ft_calloc((size_array + 1), sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size_array)
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
