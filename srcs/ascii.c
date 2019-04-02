/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:26:13 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/01 14:17:53 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_ls_ascii(t_var *v, t_flags *f)
{
	char	*name;

	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (f->a == 0 && diread->d_name[0] == '.')
			continue ;
		name = ft_strdup(diread->d_name);
		if (v->mid == NULL && ft_strcmp(v->first, name) < 0
				&& f->r == 0)
			v->mid = ft_strdup(name);
		else if (v->mid == NULL && ft_strcmp(v->first, name) > 0
				&& f->r == 1)
			v->mid = ft_strdup(name);
		else if (v->mid == NULL)
		{
			free(name);
			continue ;
		}
		if (ft_strcmp(v->first, name) < 0
				&& ft_strcmp(v->mid, name) > 0 && f->r == 0)
		{
			new_alloc(v, name, 2);
		}
		else if (ft_strcmp(v->first, name) > 0
				&& ft_strcmp(v->mid, name) < 0 && f->r == 1)
		{
			new_alloc(v, name, 2);
		}
		free(name);
	}
	closedir(v->dir);
	free(v->first);
	v->first = ft_strdup(v->mid);
	free(v->mid);
	v->mid = NULL;
}
