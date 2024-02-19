/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:24:50 by boel-bou          #+#    #+#             */
/*   Updated: 2024/01/31 10:24:58 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error1(int fd1, int ac, char **env)
{
	(void)fd1;
	if (ac < 5)
	{
		write(2, "Correct form: ./pipex file1 cmd1 .. cmdn file2\n", 47);
		exit(EXIT_FAILURE);
	}
	if (!env)
		exit(EXIT_FAILURE);
}

void	ft_write_error(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(2, &str[i++], 1);
	}
	write(2, "\n", 1);
}

char	**search_path(char **env)
{
	char	*path;
	int		i;
	char	**programm;

	path = NULL;
	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	if (!env[i])
		return (NULL);
	programm = ft_split(path, ':');
	if (!programm)
		return (NULL);
	free(path);
	return (programm);
}

char	*for_norminette5(char *h)
{
	char	*a[2];
	char	*arg;

	if (!access(h, F_OK & X_OK))
		return (h);
	a[0] = h;
	a[1] = NULL;
	arg = a[0];
	write(2, "pipex: no such file or directory: ", 35);
	ft_write_error(arg);
	exit(127);
}

char	*who_is_executable(char **env, char *h)
{
	int		i;
	char	**programm;

	i = 0;
	if (ft_strchr(h, '/') == 1)
		return (for_norminette5(h));
	programm = search_path(env);
	if (!programm)
		return (NULL);
	while (programm[i])
	{
		programm[i] = ft_strjoin(programm[i], "/");
		programm[i] = ft_strjoin(programm[i], h);
		if (!access(programm[i], F_OK & X_OK))
			break ;
		i++;
	}
	if (!programm[i])
	{
		free_split(programm);
		return (NULL);
	}
	return (programm[i]);
}
