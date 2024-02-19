/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_two_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:53:11 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 16:53:14 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	function_dup12(int k, int fd[][2], int fd2)
{
	if (dup2(fd[k][0], STDIN_FILENO) == -1)
	{
		perror("dup2a");
		exit(EXIT_FAILURE);
	}
	close(fd[k][0]);
	if (dup2(fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2b");
		exit(EXIT_FAILURE);
	}
	close(fd2);
}

void	norminette_close(int fd[][2], int k)
{
	close(fd[k][0]);
}

void	for_norminette40(int fd[][2], t_arg args, int k)
{
	close(fd[k][1]);
	if (ft_strcmp(args.argv[1], "here_doc"))
		close(args.fd3);
	else
		close(args.fd1);
}

pid_t	process_child_two_bonus(t_arg args, int fd[][2], int k, int ac)
{
	pid_t	pid;
	char	**cmd2_args;
	char	*programme;

	pid = 0;
	pid = function_fork(pid);
	if (pid == 0)
	{
		if (args.fd2 < 0)
			error_file(args.argv[ac - 1]);
		if (!ft_strlen(args.argv[ac - 2]) || !(args.argv[ac - 2]))
			for_norminette();
		for_norminette40(fd, args, k);
		close_unused_pipes(fd, k, args);
		cmd2_args = split_cmd(args.argv[ac - 2]);
		programme = who_is_executable(args.envr, cmd2_args[0]);
		if (!programme)
			print_errors(cmd2_args);
		function_dup12(k, fd, args.fd2);
		execve(programme, cmd2_args, args.envr);
		perror("execve");
		exit(EXIT_SUCCESS);
	}
	else
		return (norminette_close(fd, k), pid);
}
