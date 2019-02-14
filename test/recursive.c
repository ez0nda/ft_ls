/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:45:32 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/14 12:51:02 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	**ft_stock_names(t_flags *flag, t_var *v)
{
	int i;
	char **stock;

	i = 0;
	v->len = 0;
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (diread->d_name[0] == '.' && flag->a == 0)
			continue ;
		stock[i] = diread->d_name;
		printf("stock = %s\n", stock[i]);
		getchar();
		i++;
	}
	stock[i] = NULL;
	closedir(v->dir);
	return (stock);
}

char	*ft_putslash(t_var *v, char *str)
{
	int len;
	char *dirname;
	char *newpath;

	dirname = ft_strjoin(v->path, str);
	len = ft_strlen(dirname);
	printf("len = %d\n", len);
//	dirname = ft_strcpy(dirname, str);
	dirname[len] = '/';
	dirname[len + 1] = '\0';
	ft_printf("dirname = %s\n", dirname);
	return (dirname);
}

void	ft_recursive_flag(t_flags *flag, t_var *v)
{
	int i;
	char **stock;

	i = 0;
	flag->R = 0;
	stock = ft_stock_names(flag, v);
//	ft_display(flag, v);
/*	while (stock[i])
	{
		if (stat(ft_strjoin(v->path, stock[i]), &st) < 0)
			return ;
		if (S_ISDIR(st.st_mode))
		{
			newpath = ft_putslash(v, stock[i]);
		//	ft_printf("join = %s\n", ft_strjoin(strpath, ft_putslash(stock[i])));
		//	newpath = ft_strjoin(strpath, dirname);
		//	ft_recursive_flag(flag, v, newpath);
		}
		i++;
	}*/
	while (stock[i])
	{
		ft_printf("%s\n", stock[i]);
		i++;
	}
}
