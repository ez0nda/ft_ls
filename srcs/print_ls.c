/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:52:59 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/01 17:23:55 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print(t_var *v)
{
	if (ft_strcmp(v->first, v->last) != 0)
		ft_printf("%-*s ", v->len_n, v->first);
	else
		ft_printf("%s", v->last);
}

void	rev_init_print(t_var *v)
{
	time_t	tempo;
	char	*tmp;

	tmp = ft_strdup(v->first);
	free(v->first);
	v->first = ft_strdup(v->last);
	free(v->last);
	v->last = ft_strdup(tmp);
	free(tmp);
	tempo = v->ftime;
	v->ftime = v->ltime;
	v->ltime = tempo;
}

void	new_alloc(t_var *v, char *name, int mod)
{
	if (mod == 0)
	{
		free(v->first);
		v->first = ft_strdup(name);
	}
	if (mod == 1)
	{
		free(v->last);
		v->last = ft_strdup(name);
	}
	if (mod == 2)
	{
		free(v->mid);
		v->mid = ft_strdup(name);
	}
}

void	init_print(t_var *v, t_flags *f)
{
	char	*pathname;
	char	*name;

	v->len = 0;
	v->dir = opendir(v->path);
	if (v->dir == NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(ft_dirchr(v->path, '/'), 2);
		perror(" ");
		ft_putchar_fd('\n', 2);
		return ;
	}
	if (f->t == 0)
	{
		while ((diread = readdir(v->dir)) != NULL)
		{
			if (f->a == 0 && diread->d_name[0] == '.')
				continue ;
			name = ft_strdup(diread->d_name);
			pathname = ft_strjoin(v->path, name);
			if (lstat(pathname, &st) < 0)
				return (free_pathname(pathname, name));
			padding_all(v);
			if (v->first == NULL)
			{
				v->first = ft_strdup(name);
				v->last = ft_strdup(name);
			}
			if (ft_strcmp(v->first, name) > 0)
				new_alloc(v, name, 0);
			if (ft_strcmp(v->last, name) < 0)
				new_alloc(v, name, 1);
			if (v->len_n < ft_strlen(name))
				v->len_n = ft_strlen(name);
			free_pathname(pathname, name);
			v->len++;
		}
		closedir(v->dir);
	}
	else
		init_print_t(v, f);
	if (f->r == 1)
		rev_init_print(v);
}

int		print_ls(t_var *v, t_flags *f)
{
	init_print(v, f);
	if (f->l == 1 && v->len > 0)
		ft_printf("total %d\n", ft_count_blocks(v));
	while (v->len > 0)
	{
		if (f->l == 1)
			print_long(v);
		else
			print(v);
		if (f->t == 1 && ft_strcmp(v->first, v->last) != 0)
			print_ls_time(v, f);
		else if (ft_strcmp(v->first, v->last) != 0)
			print_ls_ascii(v, f);
		v->len--;
	}
	if (f->t == 0)
	{
		free(v->mid);
		if (v->last != NULL)
			free(v->last);
		free(v->first);
	}
	else
	{
		free(v->first);
		free(v->last);
	}
	v->first = NULL;
	v->last = NULL;
	v->len_u = 0;
	v->len_g = 0;
	v->len_n = 0;
	v->len_l = 0;
	v->len_s = 0;
	return (0);
}
