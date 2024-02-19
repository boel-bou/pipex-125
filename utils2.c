/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:06:13 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/01 14:06:17 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **h)
{
	int	i;

	i = 0;
	if (!h || !h[i])
		return ;
	while (h[i])
	{
		free(h[i]);
		i++;
	}
	free(h);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr_line(char *str, char i)
{
	int	j;

	j = 0;
	if (!str)
		return (NULL);
	while (str[j] != '\0')
	{
		if (str[j] == i)
			return (str + j);
		j++;
	}
	return (NULL);
}

char	*append_new_line(char *input)
{
	int		l;
	char	*result;

	l = ft_strlen(input);
	result = (char *)malloc((l + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, input);
	result[l] = '\n';
	result[l + 1] = '\0';
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
