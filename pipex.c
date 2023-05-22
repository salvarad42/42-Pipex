/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salvarad <salvarad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:29:44 by sr.lilitha        #+#    #+#             */
/*   Updated: 2023/05/22 13:17:23 by salvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths(char **envp)
{
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

char	*ft_get_cmd(char **paths, char *arg)
{
	char	*aux;
	char	*cmd;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(aux, arg);
		free (aux);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free (cmd);
		paths++;
	}
	return (NULL);
}

void	ft_exec(char **argv, char **envp, int i)
{
	char	**args;
	char	**paths;
	char	*cmd;

	args = ft_split(argv[i], ' ');
	paths = ft_get_paths(envp);
	cmd = ft_get_cmd(paths, args[0]);
	execve(cmd, args, envp);
	ft_print_error("pipex: command not found: ", args[0]);
	exit (0);
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
	{
		close(p[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(p[1], STDOUT_FILENO);
		ft_exec(argv, envp, 2);
	}
	else
	{
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv, envp, 3);
	}
}
