/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:29:44 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/07 00:36:58 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *command, char **envp)
{
	char	*path;

	envp[0] = 
	return (path);
}

void	ft_exec(char **argv, char **envp, int i)
{
	char	**args;
	char	*path;

	args = ft_split(argv[i], ' ');
	path = ft_get_path(args[0], envp);
	execve(path, args, envp);
	ft_print_error("pipex: command not found: ", args[0]);
	exit (0);
}

void	ft_child(int fd_in, int *p, char **argv, char **envp)
{
	close(p[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	ft_exec(argv, envp, 2);
}

void	ft_parent(int fd_out, int *p, char **argv, char **envp)
{
	close(p[1]);
	dup2(p[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	ft_exec(argv, envp, 3);
}

int	main(int argc, char **argv, char **envp)
{
	int		p[2];
	int		fd[2];

	ft_check_errors(argc, argv);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipe(p) == -1)
		return (-1);
	if (fork() == 0)
		ft_child(fd[0], p, argv, envp);
	else
		ft_parent(fd[1], p, argv, envp);
}
