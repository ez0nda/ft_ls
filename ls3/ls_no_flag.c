/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:52:59 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/22 16:04:55 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	print(t_var *v, t_flags *f)
{
	if (ft_strcmp(v->first, v->last) != 0)
		ft_printf("%-*s ", v->len_n, v->first);
	else
		ft_printf("%s", v->last);
}

void	rev_init_print(t_var *v)
{
	char	*tmp;

	tmp = ft_strdup(v->first);
	free(v->first);
	v->first = ft_strdup(v->last);
	free(v->last);
	v->last = ft_strdup(tmp);
	free(tmp);
}

void	new_alloc(t_var *v, struct dirent *diread, int mod)
{
	if (mod == 0)
	{
		free(v->first);
		v->first = ft_strdup(diread->d_name);
	}
	if (mod == 1)
	{
		free(v->last);
		v->last = ft_strdup(diread->d_name);
	}
	if (mod == 2)
	{
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
}

int		init_print(t_var *v, t_flags *f)
{
	v->dir = opendir(v->path);
	if (v->dir == NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(ft_strrchr(v->path, '/'), 2);
		perror(" ");
		return (-1);
	}
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		if (v->first == NULL)
		{
			v->first = ft_strdup(diread->d_name);
			v->last = ft_strdup(diread->d_name);
		}
		if (ft_strcmp(v->first, diread->d_name) > 0)
			new_alloc(v, diread, 0);
		if (ft_strcmp(v->last, diread->d_name) < 0)
			new_alloc(v, diread, 1);
		if (v->len_n < ft_strlen(diread->d_name))
			v->len_n = ft_strlen(diread->d_name);
		v->len++;
	}
	closedir(v->dir);
	if (f->r == 1)
		rev_init_print(v);
	return (0);
}

int		print_ls(t_var *v, t_flags *f)
{
	if (init_print(v, f) == -1)
		return (-1);
	if (f->l == 1)
		ft_printf("total %d\n", ft_count_blocks(v));
	while (v->len > 0)
	{
		if (f->l == 1)
			print_long(v, f);
		else
			print(v, f);
		if (f->t == 1 && ft_strcmp(v->first, v->last) != 0)
			print_ls_time(v, f);
		else if (ft_strcmp(v->first, v->last) != 0)
			print_ls_ascii(v, f);
		v->len--;
	}
	if (f->R == 0)
		free(v->path);
	v->len = 0;
	v->len_n = 0;
	if (f->l == 1 && f->R == 0)
	{
		free(v->first);
		free(v->last);
	}
	return (0);
}
