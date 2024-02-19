/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:39:53 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/14 10:40:27 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_errors(char **args)
{
	char	*arg;

	arg = args[0];
	write(2, "pipex: command not found: \n", 26);
	ft_write_error(arg);
	exit(127);
}

char	*remove_single_quotes(char *input)
{
	size_t	len;
	char	*result;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = ft_strlen(input);
	result = malloc(len + 1);
	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (i < len)
	{
		if (input[i] != '\'')
			result[j++] = input[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	function_fork(pid_t pid)
{
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	error_file(char *av)
{
	char	*a[2];
	char	*arg;

	a[0] = av;
	a[1] = NULL;
	arg = a[0];
	write(2, "pipex: no such file or directory: ", 35);
	ft_write_error(arg);
	exit(EXIT_FAILURE);
}
