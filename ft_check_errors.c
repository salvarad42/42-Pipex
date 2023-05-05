/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sr.lilitha <sr.lilitha@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:53:38 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/05 20:49:16 by sr.lilitha       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(char *program, char *pathname, char *str)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(pathname, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_check_errors(int argc, char **argv)
{
	int	fd;

	if (argc <= 4)
		ft_print_error(argv[0],"\0", ": invalid number of arguments");
	else if (access(argv[1], F_OK))
		ft_print_error(argv[0], argv[1], ": no such file or directory: ");
	else if (access(argv[1], R_OK))
		ft_print_error(argv[0], argv[1], ": permission denied: ");
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_print_error(argv[0], argv[1], ": is not a file: ");
	}
	fd = open(argv[argc - 1], O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		ft_print_error(argv[0], argv[argc - 1], ": permission denied: ");
	close(fd);
}
