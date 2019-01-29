/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:44:03 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/29 15:17:52 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int		main(int ac, char **av)
{
	char			*path;
	struct stat		*buf;
	int tmp;

	path = av[1];
	buf = malloc(sizeof(struct stat));
	stat(path, buf);
	tmp = buf->st_size;
	printf("%d\n", tmp);
	free(buf);
	return (0);
}
