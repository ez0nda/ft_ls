/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:52:29 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/14 13:10:07 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_recursive_flag(t_flags *flag, t_var *v)
{
	int i;
	char **stock;

	i = 0;
//	stock = ft_stock_names(flag, v);
	v->dir = opendir(v->path);
	while ((diread = readdir(v->dir)) != NULL)
	{
		if (diread->d_name[0] == '.' && flag->a == 0)
			continue ;
		stock[i] = ft_strdup(diread->d_name);
		ft_printf("stock : %s\n", stock[i]);
		i++;
	}
	stock[i] = NULL;
	closedir(v->dir);
	i = 0;
	while (stock[i])
	{
		ft_printf("stock : %s\n", stock[i]);
		i++;
	}
}
