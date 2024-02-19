/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:25:47 by boel-bou          #+#    #+#             */
/*   Updated: 2024/01/31 10:25:49 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error2(int fd2, char **av, int ac, char **env)
{
	(void)av;
	if (ac != 5)
	{
		write(2, "Correct form: ./pipex file1 cmd1 cmd2 file2\n", 44);
		exit(EXIT_FAILURE);
	}
	if (fd2 < 0)
	{
		error1(fd2, ac, env);
	}
}

void	handle_child_exit_status(int status)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
			exit(exit_status);
	}
	else
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;
	int	fd[2];
	int	status;
	int	tab[2];

	fd1 = open(av[1], O_RDONLY, 0666);
	error1(fd1, ac, env);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	error2(fd2, av, ac, env);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	tab[0] = process_child_one(av, fd1, fd, env);
	tab[1] = process_child_two(av, fd2, fd, env);
	waitpid(tab[0], &status, 0);
	waitpid(tab[1], &status, 0);
	close(fd1);
	close(fd2);
	handle_child_exit_status(status);
	return (0);
}
