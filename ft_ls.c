/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:20:50 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/04 14:45:38 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_flags flag;
	DIR *dir;
	ft_initialize(&flag);
//	ft_printf("path : %s\n", flag.path);
//	dir = opendir("test/test2/");
	if (ac > 1)
		ft_check_flag(ac - 1, av, &flag);
	// apply_flag
	// ls standard
//	closedir(dir);
	return (0);
}
