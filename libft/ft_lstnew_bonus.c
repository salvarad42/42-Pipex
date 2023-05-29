/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:03:33 by salvarad          #+#    #+#             */
/*   Updated: 2023/05/29 15:08:52 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*array;

	array = (t_list *) malloc(sizeof(t_list));
	if (!array)
		return (NULL);
	array -> content = content;
	array -> next = NULL;
	return (array);
}
