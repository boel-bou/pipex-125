/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:01:47 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 17:01:50 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cas_here_doc(char **av, int ac, t_arg *fds, char **env)
{
	(*fds).fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	error4((*fds).fd2, av, ac, env);
	(*fds).fd3 = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
}

void	cas_multiple_cmd(char **av, int ac, t_arg *fds, char **env)
{
	(*fds).fd1 = open(av[1], O_RDONLY, 0666);
	error1((*fds).fd1, ac, env);
	(*fds).fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	error4((*fds).fd2, av, ac, env);
}

void	full_env_av_tab(t_arg *args, char **av, char **env, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		args->argv[i] = ft_strdup(av[i]);
		i++;
	}
	args->argv[i] = NULL;
	i = 0;
	while (env[i])
	{
		args->envr[i] = ft_strdup(env[i]);
		i++;
	}
	args->envr[i] = NULL;
	args->tab = (pid_t *)malloc((ac - 3) * sizeof(pid_t));
}

void	full_args(t_arg *args, int ac, char **av, char **env)
{
	int	i;

	i = 0;
	if (args == NULL || av == NULL || env == NULL)
		return ;
	while (env[i])
	{
		i++;
	}
	args->argv = malloc((ac + 1) * sizeof(char *));
	args->envr = malloc((i + 1) * sizeof(char *));
	if (args->argv == NULL || args->envr == NULL)
	{
		free(args->argv);
		free(args->envr);
		return ;
	}
	full_env_av_tab(args, av, env, ac);
	args->argc = ac;
}
