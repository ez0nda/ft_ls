/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:31:13 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/05 13:58:18 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_usage(t_flags *flag, char *str, int mod)
{
	if (mod == 1)
	{
		ft_printf("ls: illegal option -- %c\n", flag->invalid);
		ft_printf("usage: ls [-lRart] [file ...]\n");
	}
	else
		ft_printf("ls: %s: No such file or directory\n", str);
}

void	ft_initialize(t_flags *flag)
{
	flag->path = ".";
	flag->path_end = NULL;
	flag->l = 0;
	flag->R = 0;
	flag->a = 0;
	flag->r = 0;
	flag->t = 0;
}
