/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:29:15 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 16:29:20 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	function_dup11(int i, int fd[][2])
{
	if (dup2(fd[i][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[i][0]);
	if (dup2(fd[i + 1][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[i + 1][1]);
}

void	close_pipes(int fd[][2], int i)
{
	close(fd[i][0]);
	close(fd[i + 1][1]);
}

void	for_norminette37(int fd[][2], t_arg args, int i)
{
	close(fd[i][1]);
	close(fd[i + 1][0]);
	if (ft_strcmp(args.argv[1], "here_doc"))
		close(args.fd3);
	else
		close(args.fd1);
}

pid_t	process_child1(char *av3, int fd[][2], int i, t_arg args)
{
	pid_t	pid;
	char	**cmd2_args;
	char	*programme;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (!ft_strlen(av3) || !(av3))
			for_norminette();
		for_norminette37(fd, args, i);
		close_unused_pipes2(fd, i, args);
		cmd2_args = split_cmd(av3);
		programme = who_is_executable(args.envr, cmd2_args[0]);
		if (!programme)
			print_errors(cmd2_args);
		function_dup11(i, fd);
		execve(programme, cmd2_args, args.envr);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (close_pipes(fd, i), pid);
}
