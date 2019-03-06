/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:20:38 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/29 16:05:39 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pf_strrev(char *s)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 0;
	while (s[n])
		n++;
	n--;
	while (i < n)
	{
		c = s[i];
		s[i] = s[n];
		s[n] = c;
		i++;
		n--;
	}
	return (s);
}
