/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_time2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:18:58 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/04 17:11:33 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	time_algo2(t_var *v)
{
	if (cmp_time(v->time_m, st.st_mtime) == 0
				&& ft_strcmp(v->mid, diread->d_name) > 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	else if (cmp_time(v->time_m, st.st_mtime) < 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
}

void	time_algo(t_var *v, int i)
{
	if ((cmp_time(v->time, st.st_mtime)) > 0 && v->time_m == 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	if (cmp_time(v->time, v->time_m) == 0
			&& cmp_time(v->time, st.st_mtime) > 0 && i == 0)
	{
		v->time_m = st.st_mtime;
		free(v->mid);
		v->mid = ft_strdup(diread->d_name);
	}
	if (cmp_time(v->time, st.st_mtime) > 0
			&& cmp_time(v->time_m, st.st_mtime) <= 0 && i == 0)
		time_algo2(v);
}

int		len_stock(t_var *v)
{
	int i;

	i = 0;
	while (v->path_long[i])
		i++;
	return i;
}
