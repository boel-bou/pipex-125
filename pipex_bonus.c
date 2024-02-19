/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:23:04 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/03 18:23:10 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error4(int fd2, char **av, int ac, char **env)
{
	(void)av;
	if (ac < 5)
	{
		write(2, "Correct form: ./pipex file1 cmd1 .. cmdn file2\n", 47);
		exit(EXIT_FAILURE);
	}
	if (fd2 < 0)
	{
		error1(fd2, ac, env);
	}
}

int	handle_child_exit_status(int status)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
			return (exit_status);
		else
			return (EXIT_SUCCESS);
	}
	else
		return (EXIT_SUCCESS);
}

int	for_norminette1(t_arg args, char **av, int fd_h[][2])
{
	int	i;
	int	status;

	i = 0;
	part_here_doc(fd_h, args, av);
	while (i < args.argc - 4)
	{
		waitpid(args.tab[i], &status, 0);
		i++;
	}
	return (handle_child_exit_status(status));
}

int	for_norminette2(t_arg args, char **av, int fd_b[][2])
{
	int	i;
	int	status;

	i = 0;
	part_multiple_cmd(fd_b, args, av);
	while (i < args.argc - 3)
	{
		waitpid(args.tab[i], &status, 0);
		i++;
	}
	return (handle_child_exit_status(status));
}

int	main(int ac, char **av, char **env)
{
	t_arg	args;
	int		fd[1024][2];
	int		exit_final;

	full_args(&args, ac, av, env);
	if (ft_strcmp((av[1]), "here_doc"))
		cas_here_doc(av, ac, &args, env);
	else
		cas_multiple_cmd(av, ac, &args, env);
	if (ft_strcmp(av[1], "here_doc"))
		exit_final = for_norminette1(args, av, fd);
	else
		exit_final = for_norminette2(args, av, fd);
	close(args.fd1);
	close(args.fd2);
	close_all_pipes(fd, args);
	free_split(args.argv);
	free_split(args.envr);
	free(args.tab);
	return (exit_final);
}
