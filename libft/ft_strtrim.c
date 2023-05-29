/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:26:59 by salvarad          #+#    #+#             */
/*   Updated: 2022/10/13 12:22:17 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	len = (int) ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr(s1, i, (len - i) + 1);
	return (str);
}
