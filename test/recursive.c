/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:22:14 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/14 20:32:49 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*void	ft_stock_names(char *str, t_flags *flag, t_var *v, char **stock)
{
	int i;

	i = 0;
	v->dir = opendir(v->path);
	ft_printf("path : %s\n", v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (diread->d_name[0] == '.' && flag->a == 0)
			continue ;
		stock[i] = ft_strdup(diread->d_name);
		i++;
	}
	stock[i] = NULL;
	closedir(v->dir);
}

void	ft_recursive_flag(char *str, t_flags *flag, t_var *v)
{
	char	*stock[50];
	int		i;

	i = 0;
	flag->R = 0;
	v->path = str;
	ft_stock_names(v->path, flag, v, stock);
	ft_printf("%s:\n", v->path);
	ft_display(flag, v);
	ft_printf("\n\n");
	while (stock[i])
	{
		if (stat(ft_strjoin(v->path, stock[i]), &st) < 0)
			return ;
		if (S_ISDIR(st.st_mode))
		{
			ft_printf("--%s--\n", ft_strjoin(v->path, ft_strjoin(stock[i], "/")));
			ft_recursive_flag(ft_strjoin(v->path, ft_strjoin(stock[i], "/")), flag, v);
		}
		i++;
	}
}*/

void	ft_stock_names(char *path, char **stock)
{
	DIR				*dir;
	struct dirent	*diread;
	int i = 0;

	dir = opendir(path);
	while ((diread = readdir(dir)) != NULL)
	{
		if (diread->d_name[0] == '.')
			continue ;
		stock[i] = ft_strdup(diread->d_name);
		i++;
	}
	stock[i] = NULL;
	closedir(dir);
}

void	print_name(char *path)
{
	DIR				*dir;
	struct dirent	*diread;

	dir = opendir(path);
	while ((diread = readdir(dir)) != NULL)
	{
		if (diread->d_name[0] == '.')
			continue ;
		printf("%s  ", diread->d_name);
	}
	closedir(dir);
}

void		ft_try(char *str, char **stock, int i)
{
			printf("--%s\n", ft_strjoin(str, ft_strjoin(stock[i], "/")));
}

void	ft_recursive_flag(char *str, t_flags *flag, t_var *v)
{
	struct stat		st;
	char			*stock[5000];
	int				i;
//	char			*tmp;

	i = 0;
	v->path = str;
	ft_stock_names(v->path, stock);
/*	while (stock[i])
	{
		printf("--%s--\n", stock[i]);
		i++;
	}*/
	flag->R = 0;
	printf("%s:\n", v->path);
//	print_name(v->path);
	ft_display(flag, v);
	printf("\n\n");
	while (stock[i])
	{
	//	ft_printf("path : %s\n", v->path);
//		printf("%s  ", stock[i]);
		if (stat(ft_strjoin(str, stock[i]), &st) < 0)
			return ;
		if (S_ISDIR(st.st_mode))
		{
		//	ft_try(str, stock, i);
	//		printf("--%s\n", ft_strjoin(str, ft_strjoin(stock[i], "/")));
			ft_recursive_flag(ft_strjoin(str, ft_strjoin(stock[i], "/")), flag, v);
		}
		i++;
	}
}

