/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:25:16 by boel-bou          #+#    #+#             */
/*   Updated: 2024/01/31 10:25:19 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	function_dup1(int fd1, int fd)
{
	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (close(fd1) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}

void	for_norminette(void)
{
	write(2, "pipex: permission denied: \n", 28);
	exit(EXIT_FAILURE);
}

void	for_norminette12(int *fd)
{
	close(fd[0]);
	close(4);
}

void	close_function2(int *fd)
{
	close(fd[1]);
}

pid_t	process_child_one(char **av, int fd1, int *fd, char **env)
{
	char	**cmd1_args;
	pid_t	pid;
	char	*programm;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (fd1 < 0)
			error_file(av[1]);
		for_norminette12(fd);
		if (!ft_strlen(av[2]) || !(av[2]))
			for_norminette();
		cmd1_args = split_cmd(av[2]);
		programm = who_is_executable(env, cmd1_args[0]);
		if (!programm)
			print_errors(cmd1_args);
		function_dup1(fd1, fd[1]);
		execve(programm, cmd1_args, env);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (close_function2(fd), pid);
}
