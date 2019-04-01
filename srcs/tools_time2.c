/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_time2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:48:57 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/01 14:19:59 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_display_time(char *time)
{
	char	*time2;
	char	*time3;

	if (ft_strcmp(time, "2019") == 0)
	{
		free(time);
		time = ft_strsub(ctime(&st.st_mtime), 4, 12);
		ft_printf(" %s ", time);
	}
	else
	{
		free(time);
		time2 = ft_strsub(ctime(&st.st_mtime), 19, 5);
		time3 = ft_strsub(ctime(&st.st_mtime), 4, 7);
		time = ft_strjoin(time3, time2);
		ft_printf(" %s ", time);
		free(time2);
		free(time3);
	}
	free(time);
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
	char	*name;
	char	*pathname;

	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (diread->d_name[0] == '.' && f->a == 0)
			continue ;
		name = ft_strdup(diread->d_name);
		pathname = ft_strjoin(v->path, name);
		if (lstat(pathname, &st))
			return (free_pathname(pathname, name));
		free_pathname(pathname, name);
		if ((v->ftime - st.st_mtime) == 0)
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
	closedir(v->dir);
	free(v->first);
	v->first = ft_strdup(v->mid);
}
