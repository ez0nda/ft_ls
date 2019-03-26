/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_time2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:48:57 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/22 16:40:55 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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

	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
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
