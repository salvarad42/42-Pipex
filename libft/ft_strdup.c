/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:05:03 by salvarad          #+#    #+#             */
/*   Updated: 2022/09/29 11:19:05 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*array;
	int		size_s1;
	int		i;

	i = 0;
	size_s1 = ft_strlen(s1);
	array = (char *) malloc (size_s1 * sizeof(char) + 1);
	if (!array)
		return (NULL);
	while (s1[i] != '\0')
	{
		array[i] = s1[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
