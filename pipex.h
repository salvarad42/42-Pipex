/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:24:56 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/22 20:54:44 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_check_errors(int argc, char **argv);
void	ft_print_error(char *str, char *pathname);
char	**ft_split_args(char const *s, char c);

#endif
