/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:41:52 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/04 18:12:22 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	time_algo_rev(t_var *v)
{
	if (cmp_time(v->time_m, st.st_mtime) == 0
			&& ft_strcmp(v->mid, diread->d_name) < 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	else if (cmp_time(v->time_m, st.st_mtime) > 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
}

int		time_rev(t_var *v, int i)
{
	if (cmp_time(v->time, st.st_mtime) == 0
			&& ft_strcmp(v->first, diread->d_name) > 0)
	{
		if (v->mid != NULL)
			free(v->mid);
		v->time_m = st.st_mtime;
		v->mid = ft_strdup(diread->d_name);
		i++;
	}
	if ((cmp_time(v->time, st.st_mtime)) < 0 && v->time_m == 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	if (cmp_time(v->time, v->time_m) == 0
			&& cmp_time(v->time, st.st_mtime) < 0 && i == 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	if (cmp_time(v->time, st.st_mtime) < 0
			&& cmp_time(v->time_m, st.st_mtime) >= 0 && i == 0)
		time_algo_rev(v);
	return (i);
}

int		save_ascii_time(t_var *v, int i)
{
	if (cmp_time(v->time, st.st_mtime) == 0
			&& ft_strcmp(v->first, diread->d_name) < 0)
	{
		if (v->mid != NULL)
			free(v->mid);
		v->time_m = st.st_mtime;
		v->mid = ft_strdup(diread->d_name);
		i++;
	}
	return (i);
}

void	time_order(t_var *v, t_flags *f)
{
	int		i;
	char	*pathname;

	i = 0;
	ft_print(v, f);
	v->save = opendir(v->path);
	while ((diread = readdir(v->save)) != NULL)
	{
		if (diread->d_name[0] == '.' && f->a == 0)
			continue ;
		pathname = ft_strjoin(v->path, diread->d_name);
		if (stat(pathname, &st) < 0)
		{
			free(pathname);
			return ;
		}
		free(pathname);
		if (f->r == 1)
		{
			i = time_rev(v, i);
			continue ;
		}
		i = save_ascii_time(v, i);
		time_algo(v, i);
	}
	closedir(v->save);
	if (cmp_time(v->time, v->time_m) == 0)
		ascii_time(v, f);
	free(v->first);
	v->first = ft_strdup(v->mid);
	v->time = v->time_m;
}

void	init_flag_t(t_var *v, t_flags *f)
{
	int		i;
	char	*pathname;

	i = 0;
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		pathname = ft_strjoin(v->path, diread->d_name);
		if (stat(pathname, &st) < 0)
		{
			free(pathname);
			return ;
		}
		free(pathname);
		algo_init_t(v, i);
		if (cmp_time(st.st_mtime, v->time_l) <= 0)
		{
			if (ft_strcmp(v->last, diread->d_name) < 0
					|| cmp_time(st.st_mtime, v->time_l) < 0)
			{
				free(v->last);
				v->last = ft_strdup(diread->d_name);
				v->time_l = st.st_mtime;
			}
		}
		i++;
	}
	closedir(v->dir);
	init_flag_t_r(v, f);
}
