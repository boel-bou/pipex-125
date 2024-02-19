/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:06:52 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/12 14:06:56 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_pipes(int fd[][2], int i, t_arg fds)
{
	int	j;
	int	ac;

	j = 0;
	if (ft_strcmp(fds.argv[1], "here_doc"))
		ac = fds.argc - 5;
	else
		ac = fds.argc - 4;
	while (j < ac)
	{
		if (j != i)
		{
			close(fd[j][0]);
			close(fd[j][1]);
		}
		j++;
	}
}

void	close_unused_pipes2(int fd[][2], int i, t_arg fds)
{
	int	j;
	int	ac;

	j = 0;
	if (ft_strcmp(fds.argv[1], "here_doc"))
		ac = fds.argc - 5;
	else
		ac = fds.argc - 4;
	while (j < ac)
	{
		if (j == i || j == i + 1)
			j++;
		else
		{
			close(fd[j][0]);
			close(fd[j][1]);
			j++;
		}
	}
}

void	close_all_pipes(int fd[][2], t_arg fds)
{
	int	j;
	int	ac;

	j = 0;
	if (ft_strcmp(fds.argv[1], "here_doc"))
		ac = fds.argc - 5;
	else
		ac = fds.argc - 4;
	while (j < ac)
	{
		close(fd[j][0]);
		close(fd[j][1]);
		j++;
	}
}
