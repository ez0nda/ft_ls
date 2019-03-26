/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:24:42 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/26 13:37:42 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		free_pathname(char *pathname)
{
	free(pathname);
	return (-1);
}

int		init_print_t(t_var *v, t_flags *f)
{
	char	*pathname;

	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		pathname = ft_strjoin(v->path, diread->d_name);
		if (stat(pathname, &st) < 0)
			return (free_pathname(pathname));
		free(pathname);
		if (v->first == NULL)
		{
			v->first = ft_strdup(diread->d_name);
			v->ftime = st.st_mtime;
			v->last = ft_strdup(diread->d_name);
			v->ltime = st.st_mtime;
		}
		if ((st.st_mtime - v->ftime) >= 0)
		{
			if (ft_strcmp(v->first, diread->d_name) > 0
					|| (st.st_mtime - v->ftime) > 0)
			{
				free(v->first);
				v->first = ft_strdup(diread->d_name);
				v->ftime = st.st_mtime;
			}
		}
		if ((st.st_mtime - v->ltime) <= 0)
		{
			if (ft_strcmp(v->last, diread->d_name) < 0
					|| (st.st_mtime - v->ltime) < 0)
			{
				free(v->last);
				v->last = ft_strdup(diread->d_name);
				v->ltime = st.st_mtime;
			}
		}
		v->len++;
	}
	closedir(v->dir);
	return (0);
}

int		print_ls_time(t_var *v, t_flags *f)
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
			return (free_pathname(pathname));
		free(pathname);
		if (f->r == 1)
		{
			i = time_rev(v, i);
			continue ;
		}
		i = save_ascii_time(v, i);
		time_algo(v, i);
	}
	closedir(v->dir);
	if ((v->ftime - v->mtime) == 0)
		ascii_time(v, f);
	free(v->first);
	v->first = ft_strdup(v->mid);
	v->ftime = v->mtime;
	return (0);
}
