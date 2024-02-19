/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_one_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:51:37 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 16:51:40 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	function_dup13(int fd[][2], int i, int fd1)
{
	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd1);
	if (dup2(fd[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[i][1]);
}

void	close_function3(int fd[][2])
{
	close(fd[0][1]);
}

void	for_norminette60(int fd[][2], t_arg fds)
{
	close(fd[0][0]);
	close(fds.fd2);
}

pid_t	process_child_one_bonus(char *av2, t_arg fds, int fd[][2])
{
	char	**cmd1_args;
	pid_t	pid;
	char	*programm;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (fds.fd1 < 0)
			error_file(fds.argv[1]);
		for_norminette60(fd, fds);
		if (!ft_strlen(av2) || !(av2))
			for_norminette();
		close_unused_pipes(fd, 0, fds);
		cmd1_args = split_cmd(av2);
		programm = who_is_executable(fds.envr, cmd1_args[0]);
		if (!programm)
			print_errors(cmd1_args);
		function_dup13(fd, 0, fds.fd1);
		execve(programm, cmd1_args, fds.envr);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (close_function3(fd), pid);
}
