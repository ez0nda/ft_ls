/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:26:13 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/22 16:03:35 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	print_ls_ascii(t_var *v, t_flags *f)
{
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		if (v->mid == NULL && ft_strcmp(v->first, diread->d_name) < 0
				&& f->r == 0)
			v->mid = ft_strdup(diread->d_name);
		else if (v->mid == NULL && ft_strcmp(v->first, diread->d_name) > 0
				&& f->r == 1)
			v->mid = ft_strdup(diread->d_name);
		else if (v->mid == NULL)
			continue ;
		if (ft_strcmp(v->first, diread->d_name) < 0
				&& ft_strcmp(v->mid, diread->d_name) > 0 && f->r == 0)
			new_alloc(v, diread, 2);
		else if (ft_strcmp(v->first, diread->d_name) > 0
				&& ft_strcmp(v->mid, diread->d_name) < 0 && f->r == 1)
			new_alloc(v, diread, 2);
	}
	closedir(v->dir);
	free(v->first);
	v->first = ft_strdup(v->mid);
	free(v->mid);
	v->mid = NULL;
}
