/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:25:55 by ezonda            #+#    #+#             */
/*   Updated: 2019/03/20 11:34:48 by ezonda           ###   ########.fr       */
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
	if (dir == NULL)
	{
		perror("error");
		return (-1);
	}
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

static char		*ft_init_stat_path(char *str, char *stock, int mod)
{
	char	*new;
	char	*tmp;

	if (mod == 1)
	{
		if (!(new = ft_strjoin(str, stock)))
			return (NULL);
	}
	else
	{
		if (!(tmp = ft_strjoin(stock, "/")))
			return (NULL);
		if (!(new = ft_strjoin(str, tmp)))
			return (NULL);
		free(tmp);
	}
	return (new);
}

void			ft_recursive_flag(char *str, t_flags *flag, t_var *v)
{
	char			**stock;
	int				name_count;
	int				i;
	char			*recursive_path;

	i = 0;
	v->path = str;
	name_count = ft_count_names(v->path, flag);
	if (name_count == -1)
		return ;
	if (!(stock = (char**)malloc(sizeof(char*) * name_count + 1)))
		return ;
	ft_stock_names(v->path, stock, flag);
	flag->R = 2;
	ft_putstr("\n\n");
	ft_putstr(v->path);
	ft_putstr(":\n");
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (flag->a != 1 && diread->d_name[0] == '.')
			continue ;
		ft_printf("  %s  ", diread->d_name);
	}
	closedir(v->dir);
	while (stock[i])
	{
		v->path = ft_init_stat_path(str, stock[i], 1);
		if (stat(v->path, &st) < 0)
			return ;
		free(v->path);
		if (S_ISDIR(st.st_mode))
		{
			recursive_path = ft_init_stat_path(str, stock[i], 2);
			ft_recursive_flag(recursive_path, flag, v);
			free(recursive_path);
		}
		free(stock[i]);
		i++;
	}
	free(stock);
}

int				main(void)
{
	t_flags		flag;
	t_var		v;

	ft_recursive_flag("./", &flag, &v);
	return (0);
}
