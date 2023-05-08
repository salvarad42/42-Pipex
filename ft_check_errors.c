/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:53:38 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/06 23:54:58 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(char *str, char *pathname)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(pathname, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_check_errors(int argc, char **argv)
{
	int	fd;

	if (argc != 5)
		ft_print_error("pipex: invalid number of arguments", argv[1]);
	else if (access(argv[1], F_OK))
		ft_print_error("pipex: no such file or directory: ", argv[1]);
	else if (access(argv[1], R_OK))
		ft_print_error("pipex: permission denied: ", argv[1]);
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_print_error("pipex: is not a file: ", argv[1]);
	}
	fd = open(argv[argc - 1], O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		ft_print_error("pipex: permission denied: ", argv[argc - 1]);
	close(fd);
}
