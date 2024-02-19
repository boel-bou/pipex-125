/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:25:32 by boel-bou          #+#    #+#             */
/*   Updated: 2024/01/31 10:25:36 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	which_cmd(char *av)
{
	if (ft_strcmp(av, "awk"))
		return (1);
	if (ft_strcmp(av, "sed"))
		return (1);
	if (ft_strcmp(av, "echo"))
		return (1);
	if (ft_strcmp(av, "grep"))
		return (1);
	return (0);
}

char	**split_cmd(char *av)
{
	char	**cmd_args;
	int		i;

	if (!av)
		return (NULL);
	cmd_args = ft_split(av, ' ');
	i = 2;
	if (which_cmd(cmd_args[0]))
	{
		av = remove_single_quotes(av);
		cmd_args = ft_split(av, ' ');
		free(av);
		if (cmd_args[1])
		{
			while (cmd_args[i])
			{
				cmd_args[1] = ft_strjoin(cmd_args[1], " ");
				cmd_args[1] = ft_strjoin(cmd_args[1], cmd_args[i]);
				cmd_args[i] = NULL;
				i++;
			}
		}
		return (cmd_args);
	}
	return (cmd_args);
}

void	function_dup2(int fd2, int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
}

void	for_norminette77(int *fd, int fd2)
{
	close(fd[1]);
	if (fd2 == 4)
		close(3);
}

pid_t	process_child_two(char **av, int fd2, int *fd, char **env)
{
	pid_t	pid;
	char	**cmd2_args;
	char	*programme;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (fd2 < 0)
			error_file(av[4]);
		if (!ft_strlen(av[3]) || !(av[3]))
			for_norminette();
		for_norminette77(fd, fd2);
		cmd2_args = split_cmd(av[3]);
		programme = who_is_executable(env, cmd2_args[0]);
		if (!programme)
			print_errors(cmd2_args);
		function_dup2(fd2, fd[0]);
		execve(programme, cmd2_args, env);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (close(fd[0]), pid);
}
