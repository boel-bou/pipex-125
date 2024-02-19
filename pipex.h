/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:27:01 by boel-bou          #+#    #+#             */
/*   Updated: 2024/01/31 10:27:07 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct t_arg
{
	char	**argv;
	char	**envr;
	int		argc;
	int		fd1;
	int		fd2;
	int		fd3;
	pid_t	*tab;
}			t_arg;

char		**ft_split(char const *s, char c);
int			ft_strchr(char *str, char i);
char		*ft_strdup(char *s);
char		*ft_strcpy(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr_line(char *str, char i);
char		**search_path(char **env);
char		*who_is_executable(char **env, char *h);
int			ft_strlen(char *str);
char		*get_next_line(int fd);
void		ft_write_error(char *str);
void		error1(int fd1, int ac, char **env);
void		error4(int fd2, char **av, int ac, char **env);
void		error_file(char *av);
void		print_errors(char **arg);
pid_t		process_child_one(char **av, int fd1, int *fd, char **env);
pid_t		process_child_two(char **av, int fd2, int *fd, char **env);
void		cas_here_doc(char **av, int ac, t_arg *fds, char **env);
void		cas_multiple_cmd(char **av, int ac, t_arg *fds, char **env);
void		full_env_av_tab(t_arg *args, char **av, char **env, int ac);
void		full_args(t_arg *args, int ac, char **av, char **env);
int			get_input(char **av, t_arg fds);
void		part_here_doc(int fd[][2], t_arg fds, char **av);
void		part_multiple_cmd(int fd[][2], t_arg fds, char **av);
void		free_split(char **str);
int			which_cmd(char *av);
int			function_fork(pid_t pid);
char		*remove_single_quotes(char *input);
char		**split_cmd(char *av);
int			ft_strcmp(char *s1, char *s2);
void		for_norminette(void);
char		*append_new_line(char *input);
pid_t		process_child_one_bonus(char *av2, t_arg fds, int fd[][2]);
pid_t		process_child_two_bonus(t_arg args, int fd[][2], int k, int ac);
pid_t		process_child1(char *av3, int fd[][2], int i, t_arg args);
pid_t		process_child_here_dock(t_arg args, int fd3, int fd[][2]);
void		close_unused_pipes(int fd[][2], int i, t_arg args);
void		close_unused_pipes2(int fd[][2], int i, t_arg fds);
void		close_all_pipes(int fd[][2], t_arg fds);
#endif
