/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:57:06 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/02 15:36:26 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

static int		close_dir(t_var *v, int i, char *s1, char *s2)
{
	if (i == 0 || i == 2)
	{
		free(s1);
		free(s2);
	}
	if (i == 1 || i == 0)
		closedir(v->dir);
	if (i == 0)
		return (2);
	return (1);
}

char	*ft_dirchr(char *str, int c)
{
	int i;

	i = ft_strlen(str);
	i -= 2;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char*)&str[i + 1]);
		i--;
	}
	return (NULL);
}

int		is_file(char *s, t_var *v)
{
	v->dir = opendir("./");
	while ((diread = readdir(v->dir)) != NULL)
		if (ft_strcmp(diread->d_name, s) == 0)
			return (close_dir(v, 1, NULL, NULL));
	closedir(v->dir);
	if (lstat(s, &st) < 0)
		return (0);
	if (S_ISLNK(st.st_mode))
		return (1);
	return (0);
}

int		is_file_n(char *s, t_var *v)
{
	int		start;
	int		end;
	char	*path_d;
	char	*path;

	end = 0;
	start = 0;
	if (ft_strchr(s, '/') != NULL)
	{
		while (s[start])
			start++;
		end = start;
		while (s[start] != '/')
			start--;
		path_d = ft_strsub(s, 0, start);
		path = ft_strsub(s, start + 1, end - start);
		if ((v->dir = opendir(path_d)) == NULL)
		{
			ft_usage(v, s, 0);
			return (close_dir(v, 2, path_d, path));
		}
		while ((diread = readdir(v->dir)) != NULL)
			if (ft_strcmp(diread->d_name, path) == 0)
				return (close_dir(v, 0, path_d, path));
		close_dir(v, 2, path_d, path);
	}
	ft_usage(v, s, 0);
	return (0);
}

int		is_directory(char *s)
{
	if (lstat(s, &st) < 0)
		return (0);
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}
