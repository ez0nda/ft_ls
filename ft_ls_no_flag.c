/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_no_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:58:42 by jebrocho          #+#    #+#             */
/*   Updated: 2019/02/08 13:45:58 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void		ft_print_name(struct dirent diread, t_var *v)
{
	if (ft_strcmp(diread.d_name, v->last) == 0)
		ft_printf("%s", diread.d_name);
	else
		ft_printf("%-*s ", v->len, diread.d_name);
}

static int		ft_cmp_name(char **av, char *str)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], str) == 0)
			return (0);
		else
			return (-1);
		i++;
	}
	return (-1);
}
/*
int				ft_print_path(char **av)
{
	struct dirent *diread;
	DIR			*dir;
	t_stru		stru;

	stru.len = 0;
	dir = opendir(".");
	while ((diread = readdir(dir)) != NULL)
	{
		if (stru.len < ft_strlen(diread->d_name))
			stru.len = ft_strlen(diread->d_name);
		stru.last = ft_strdup(diread->d_name);
	}
	closedir(dir);
	dir = opendir(".");
	while ((diread = readdir(dir)) != NULL)
		if (diread->d_name[0] != '.')
			ft_print_name(*diread, stru);
	closedir(dir);
	return (0);
}*/

int		ft_ls_no_flag(t_var *v)
{
	v->len = 0;
	v->dir = opendir(".");
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (v->len < ft_strlen(diread->d_name))
			v->len = ft_strlen(diread->d_name);
		v->last = ft_strdup(diread->d_name);
	}
	closedir(v->dir);
	v->dir = opendir(".");
	while ((diread = readdir(v->dir)) != NULL)
		if (diread->d_name[0] != '.')
			ft_print_name(*diread, v);
	closedir(v->dir);
	return (1);
}
