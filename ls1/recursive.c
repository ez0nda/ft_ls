/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:22:14 by ezonda            #+#    #+#             */
/*   Updated: 2019/03/05 17:36:41 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int		ft_count_names(char *strpath, t_flags *flag)
{
	DIR				*dir;
	struct dirent	*diread;
	int				count;

	count = 0;
	dir = opendir(strpath);
	while ((diread = readdir(dir)) != NULL)
	{
		if (flag->a == 0 && diread->d_name[0] == '.')
			continue ;
		count++;
	}
	closedir(dir);
	return (count);
}

static void		ft_stock_names(char *strpath, char **stock, t_flags *flag)
{
	DIR				*dir;
	struct dirent	*diread;
	int				i;

	i = 0;
	dir = opendir(strpath);
	while ((diread = readdir(dir)) != NULL)
	{
		if (flag->a == 0 && diread->d_name[0] == '.')
			continue ;
		else if (flag->a == 1)
		{
			if (diread->d_name[0] == '.'
					&& (diread->d_name[1] == '.' || diread->d_name[1] == '\0'))
				continue ;
		}
		stock[i] = ft_strdup(diread->d_name);
		i++;
	}
	stock[i] = NULL;
	closedir(dir);
}

static char		*ft_init_stat_path(char *str, char *stock)
{
	char	*new;

	if (!(new = ft_strjoin(str, stock)))
		return (NULL);
	return (new);
}

static char		*ft_init_recursive_path(char *str, char *stock)
{
	char *new;
	char *tmp;

	if (!(tmp = ft_strjoin(stock, "/")))
		return (NULL);
	if (!(new = ft_strjoin(str, tmp)))
		return (NULL);
	free(tmp);
	return (new);
}

void			ft_recursive_flag(char *str, t_flags *flag, t_var *v)
{
	struct stat		st;
	char			*stock[256];
	int				name_count;
	int				i;
	char			*stat_path;
	char			*recursive_path;

	i = 0;
	v->path = str;
	name_count = ft_count_names(v->path, flag);
//	if (!(stock = (char**)malloc(sizeof(char*) * name_count + 1)))
//		return ;
	ft_stock_names(v->path, stock, flag);
	flag->R = 2;
	ft_putstr(v->path);
	ft_putstr(":\n");
	ft_display(flag, v);
	free(v->first);
	ft_putstr("\n\n");
	free(v->last);
	while (stock[i])
	{
		stat_path = ft_init_stat_path(str, stock[i]);
		if (stat(stat_path, &st) < 0)
			return ;
		free(stat_path);
		free(stock[i]);
		if (S_ISDIR(st.st_mode))
		{
			recursive_path = ft_init_recursive_path(str, stock[i]);
			ft_recursive_flag(recursive_path, flag, v);
			free(recursive_path);
		}
		i++;
	}
}
