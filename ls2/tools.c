/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:31:13 by ezonda            #+#    #+#             */
/*   Updated: 2019/03/04 16:12:39 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_count_blocks(t_var *v)
{
	int		count;
	char	*pathname;

	count = 0;
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)))
	{
		pathname = ft_strjoin(v->path, diread->d_name);
		if (stat(pathname, &st) < 0)
			return (0);
		if (lstat(pathname, &st) < 0)
			return (0);
		count += st.st_blocks;
		free(pathname);
	}
	closedir(v->dir);
	return (count);
}

void	ft_usage(t_var *v, char *str, int mod)
{
	if (mod == 1)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(v->invalid, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ./ft_ls [-lRart] [file ...]", 2);
	}
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void	ft_initialize(t_flags *flag, t_var *v, char **av)
{
	v->path = ft_strdup("./");
	v->path_end = NULL;
	v->file_path = 0;
	v->is_link = 0;
	flag->l = 0;
	flag->R = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
	v->len = 0;
	v->len_file = 0;
	v->len_link = 0;
	v->path_long = av;
	v->c_dir = 0;
	v->time_m = 0;
	v->mid = NULL;
}

int		ft_nbrlen(int nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}