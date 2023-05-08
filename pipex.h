/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sr.lilitha <sr.lilitha@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:24:56 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/06 01:49:40 by sr.lilitha       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_check_errors(int argc, char **argv);
void	ft_print_error(char *program, char *pathname, char *str);
void	pipex(int argc, char **argv);

#endif
