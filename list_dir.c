/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:50:11 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/29 15:19:01 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	DIR				*dip;
	struct dirent	*dit;

	if (ac >= 1)
	{
		dip = opendir(av[1]);
		while ((dit = readdir(dip)) != NULL)
			printf("%s\n", dit->d_name);
		closedir(dip);
	}
	return (0);
}
