/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:44:20 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/14 10:44:29 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	function_dup_herdock(int fd[][2], int fd3)
{
	if (dup2(fd3, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd3);
	if (dup2(fd[0][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[0][1]);
}

void	for_norminette50(int fd[][2], t_arg args)
{
	close(fd[0][0]);
	close(args.fd2);
}

pid_t	process_child_here_dock(t_arg args, int fd3, int fd[][2])
{
	char	**cmd1_args;
	pid_t	pid;
	char	*programm;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (!ft_strlen(args.argv[3]) || !(args.argv[3]))
			for_norminette();
		for_norminette50(fd, args);
		close_unused_pipes(fd, 0, args);
		cmd1_args = split_cmd(args.argv[3]);
		programm = who_is_executable(args.envr, cmd1_args[0]);
		if (!programm)
			print_errors(cmd1_args);
		function_dup_herdock(fd, fd3);
		execve(programm, cmd1_args, args.envr);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (close(fd[0][1]), pid);
}
