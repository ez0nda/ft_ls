/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:49:29 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/04 18:16:51 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		cmp_time(time_t s1, time_t s2)
{
	return (s1 - s2);
}

void	ascii_time_rev(t_var *v, char *s)
{
	if (ft_strcmp(v->first, v->mid) == 0
			&& (ft_strcmp(v->first, s) > 0))
	{
		free(v->mid);
		v->mid = ft_strdup(s);
	}
	if ((ft_strcmp(v->first, s) > 0)
			&& (ft_strcmp(v->mid, s) < 0))
	{
		free(v->mid);
		v->mid = ft_strdup(s);
	}
}

void	ascii_time(t_var *v, t_flags *f)
{
	char	*pathname;

	v->save = opendir(v->path);
	while ((diread = readdir(v->save)) != NULL)
	{
		if (diread->d_name[0] == '.' && f->a == 0)
			continue ;
		pathname = ft_strjoin(v->path, diread->d_name);
		if (stat(pathname, &st))
		{
			free(pathname);
			return ;
		}
		free(pathname);
		if (cmp_time(v->time, st.st_mtime) == 0)
		{
			if (f->r == 1)
			{
				ascii_time_rev(v, diread->d_name);
				continue ;
			}
			if (ft_strcmp(v->first, v->mid) == 0
					&& (ft_strcmp(v->first, diread->d_name) < 0))
			{
				free(v->mid);
				v->mid = ft_strdup(diread->d_name);
			}
			if ((ft_strcmp(v->first, diread->d_name) < 0)
					&& (ft_strcmp(v->mid, diread->d_name) > 0))
			{
				free(v->mid);
				v->mid = ft_strdup(diread->d_name);
			}
		}
	}
	closedir(v->save);
}

void	init_flag_t_r(t_var *v, t_flags *f)
{
	if (f->r == 1)
	{
		v->time_m = v->time;
		v->time = v->time_l;
		v->time_l = v->time_m;
		v->time_m = 0;
		v->mid = ft_strdup(v->first);
		free(v->first);
		v->first = ft_strdup(v->last);
		free(v->last);
		v->last = ft_strdup(v->mid);
		free(v->mid);
		v->mid = NULL;
	}
}

void	algo_init_t(t_var *v, int i)
{
	if (i == 0)
	{
		free(v->first);
		free(v->last);
		v->last = ft_strdup(diread->d_name);
		v->time_l = st.st_mtime;
		v->first = ft_strdup(diread->d_name);
		v->time = st.st_mtime;
	}
	if (cmp_time(st.st_mtime, v->time) >= 0)
	{
		if (ft_strcmp(v->first, diread->d_name) > 0
			|| cmp_time(st.st_mtime, v->time) > 0)
		{
			free(v->first);
			v->first = ft_strdup(diread->d_name);
			v->time = st.st_mtime;
		}
	}
}
