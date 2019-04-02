/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:24:45 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/02 14:14:18 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	padding_dev(t_var *v)
{
	int nb_min;
	int nb_maj;

	nb_maj = (st.st_rdev >> 8) / 65536;
	nb_min = st.st_rdev & 0xFF;
	if (v->len_dmaj < (4 - nbrsize(nb_maj)))
		v->len_dmaj = 4 - nbrsize(nb_maj);
	if (v->len_dmin < (3 - nbrsize(nb_min)))
		v->len_dmin = 3 - nbrsize(nb_min);
	if (v->len_n < ft_strlen(diread->d_name))
		v->len_n = ft_strlen(diread->d_name);
	if (S_ISCHR(st.st_mode))
		v->is_dev = 1;
}

void	ft_display_dev(t_var *v)
{
	int nb_min;
	int nb_maj;

	nb_maj = (st.st_rdev >> 8) / 65536;
	nb_min = st.st_rdev & 0xFF;
	ft_printf("%*d, %*d", v->len_dmaj, nb_maj, v->len_dmin, nb_min);
}

void	padding_file(char **s, t_var *v)
{
	char *path;
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] != '/')
			path = ft_strjoin("./", s[i]);
		else
			path = ft_strdup(s[i]);
		if (lstat(path, &st) < 0)
			return (free(path));
		free(path);
		padding_all(v);
		i++;
	}
}
