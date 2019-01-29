/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:19:32 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/29 15:33:36 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char buf[1024];
	ssize_t len;

	if ((len = readlink(av[1], buf, sizeof(buf))) != 1)
	{
		printf("len : %ld\n", len);
		buf[len] = '\0';
	}
	return (0);
}
