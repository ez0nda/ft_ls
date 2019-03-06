/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:09:17 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/04 18:10:55 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		is_path(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_flags		flag;
	t_var		v;

	ft_initialize(&flag, &v, av);
	if (is_path(av) == 1)
	{
		initialize_stock_dir(&v);
		ascii_init(&v, ac);
	}
	if (ac == 1)
		return (ft_ls_no_flag(&v, &flag));
	if (ac > 1)
		ft_check_flag(ac - 1, av, &flag, &v);
	if (flag.t == 1 && v.file_path == 1)
	{
		time_path(&v, ac);
		init_last(&v, ac);
	}
	if (flag.r == 1 && v.file_path == 1)
	{
		v.path_long = rev_order(v.path_long);
		init_last(&v, ac);
	}
	ft_display(&flag, &v);
	if (is_path(av) == 1)
		free(v.stock_d);
//	while (1);
	return (0);
}
