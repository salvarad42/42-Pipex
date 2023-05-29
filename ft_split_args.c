/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:08:32 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/29 10:57:14 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_quote(const char *s, int i)
{
	int	aux;

	if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] == ' ')
		aux = 1;
	if ((s[i] == '\'' || s[i] == '\"') && s[i + 1] == ' ')
		aux = 0;
	return (aux);
}

int	ft_count_subargs(char const *s, char c)
{
	int	i;
	int	count;
	int	aux;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		aux = ft_is_quote(s, i);
		if (s[i] != c && (i == 0 || s[i - 1] == c) && aux == 0)
			count++;
		i++;
	}
	return (count);
}

int	ft_subargslen(int start, char const *s, char c, int aux)
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

char	**ft_split_args(char const *s, char c)
{
	int		i;
	int		count;
	int		len;
	int		start;
	char	**array;

	count = ft_count_subargs(s, c);
	array = (char **) ft_calloc((count + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	len = 0;
	while (i < count)
	{
		start = ft_subargslen((start + len), s, c, 1);
		len = ft_subargslen(start, s, c, 0);
		array[i] = ft_substr(s, start, len);
		i++;
	}
	array[i] = NULL;
	return (array);
}
