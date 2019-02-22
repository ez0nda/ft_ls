/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:41:52 by jebrocho          #+#    #+#             */
/*   Updated: 2019/02/21 16:53:26 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		cmp_time(char *s1, char *s2)
{
	printf("\n1:%s2:%s\n", s1, s2);
	return (0);
}

void	time_order(t_var *v, t_flags *f)
{
	int i;

	i = 0;
	ft_print(v, f);
	v->save = opendir(v->path);
	while ((diread = readdir(v->save)) != NULL)
	{
		if (diread->d_name[0] == '.' && f->a == 0)
			continue ;
		if (stat(ft_strjoin(v->path, diread->d_name), &st) < 0)
			return ;
		if (ft_strcmp(v->time, ctime(&st.st_mtime)) > 0 && v->time_m == NULL)
		{
			v->time_m = ft_strdup(ctime(&st.st_mtime));
			v->mid = ft_strdup(diread->d_name);
		}
		if (ft_strcmp(v->time, v->time_m) == 0
			&& ft_strcmp(v->time, ctime(&st.st_mtime)) >= 0)
		{
			if (ft_strcmp(v->mid, diread->d_name) != 0)
			{
				v->time_m = ft_strdup(ctime(&st.st_mtime));
				v->mid = ft_strdup(diread->d_name);
			}
		}
		if (ft_strcmp(v->time, ctime(&st.st_mtime)) > 0
			&& ft_strcmp(v->time_m, ctime(&st.st_mtime)) < 0)
		{
//			printf("\nt:%st_m:%s\n", v->time, v->time_m);
			v->time_m = ft_strdup(ctime(&st.st_mtime));
			v->mid = ft_strdup(diread->d_name);
		}
	}
//	cmp_time(v->time, v->time_l);
	closedir(v->save);
	v->first = v->mid;
	v->time = v->time_m;
}

void	init_flag_t(t_var *v, t_flags *f)
{
	int i;

	i = 0;
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		if (stat(ft_strjoin(v->path, diread->d_name), &st) < 0)
			return ;
		if (i == 0)
			v->time = ft_strdup(ctime(&st.st_mtime));
		if (i == 0)
			v->time_l = ft_strdup(ctime(&st.st_mtime));
		if (ft_strcmp(ctime(&st.st_mtime), v->time) > 0)
		{
			v->first = ft_strdup(diread->d_name);
			v->time = ft_strdup(ctime(&st.st_mtime));
		}
		if (ft_strcmp(ctime(&st.st_mtime), v->time_l) <= 0)
		{
			v->last = ft_strdup(diread->d_name);
			v->time_l = ft_strdup(ctime(&st.st_mtime));
		}
		i++;
	}
	closedir(v->dir);
}
