/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:03:49 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 17:03:52 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_input(char **av, t_arg fds)
{
	char	*line;
	int		fd_in;
	char	*str;

	line = get_next_line(0);
	str = append_new_line(av[2]);
	while (line != NULL)
	{
		if (ft_strcmp(line, str))
		{
			free(str);
			free(line);
			break ;
		}
		write(fds.fd3, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	fd_in = open("file.txt", O_RDONLY, 0666);
	return (fd_in);
}

void	part_here_doc(int fd[][2], t_arg fds, char **av)
{
	int	i;
	int	l;
	int	fd_in;

	i = 0;
	while (i < fds.argc - 5)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fd_in = get_input(av, fds);
	fds.tab[0] = process_child_here_dock(fds, fd_in, fd);
	unlink("file.txt");
	l = 4;
	i = -1;
	while (++i < fds.argc - 6)
	{
		fds.tab[i + 1] = process_child1(av[l], fd, i, fds);
		l++;
	}
	fds.tab[i + 1] = process_child_two_bonus(fds, fd, i, fds.argc);
}

void	part_multiple_cmd(int fd[][2], t_arg fds, char **av)
{
	int	i;
	int	l;

	i = 0;
	while (i < fds.argc - 4)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fds.tab[0] = process_child_one_bonus(av[2], fds, fd);
	l = 3;
	i = 0;
	while (i < fds.argc - 5)
	{
		fds.tab[i + 1] = process_child1(av[l], fd, i, fds);
		i++;
		l++;
	}
	fds.tab[i + 1] = process_child_two_bonus(fds, fd, i, fds.argc);
}
