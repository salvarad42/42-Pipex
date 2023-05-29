/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:08:32 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/05 13:08:54 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_substr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	ft_substrlen(int start, char const *s, char c, int aux)
{
	int	len;

	len = 0;
	while (s[start] == c && s[start] != '\0')
		start++;
	if (aux == 1)
		return (start);
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	int		len;
	int		start;
	char	**array;

	count = ft_count_substr(s, c);
	array = (char **) ft_calloc((count + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	len = 0;
	while (i < count)
	{
		start = ft_substrlen((start + len), s, c, 1);
		len = ft_substrlen(start, s, c, 0);
		array[i] = ft_substr(s, start, len);
		i++;
	}
	array[i] = NULL;
	return (array);
}
