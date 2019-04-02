/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:45:10 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/02 14:42:21 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**rev_order(char **tab)
{
	char	*tab_save;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	k = j;
	if (j > 1)
	{
		j--;
		while (i < j)
		{
			tab_save = tab[i];
			tab[i] = tab[j];
			tab[j] = tab_save;
			i++;
			j--;
		}
		tab[k] = NULL;
	}
	return (tab);
}

char	**ascii_time_path(char **tab, t_var *v)
{
	char	*pathname;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		pathname = ft_strjoin(v->path, tab[j]);
		if (lstat(pathname, &st) < 0)
			return (free_path_stat(pathname));
		free(pathname);
		v->ftime = st.st_mtime;
		while (tab[i])
		{
			pathname = ft_strjoin(v->path, tab[i]);
			if (lstat(pathname, &st) < 0)
				return (free_path_stat(pathname));
			free(pathname);
			if ((v->ftime - st.st_mtime) == 0
					&& ft_strcmp(tab[j], tab[i]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				v->ftime = st.st_mtime;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (tab);
}

char	**time_multi_path(char **tab, t_var *v)
{
	char	*pathname;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tab[j])
	{
		pathname = ft_strjoin(v->path, tab[j]);
		if (lstat(pathname, &st) < 0)
			return (free_path_stat(pathname));
		free(pathname);
		v->ftime = st.st_mtime;
		while (tab[i])
		{
			pathname = ft_strjoin(v->path, tab[i]);
			if (lstat(pathname, &st) < 0)
				return (free_path_stat(pathname));
			free(pathname);
			if ((v->ftime - st.st_mtime) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
				v->ftime = st.st_mtime;
			}
			i++;
		}
		i = 0;
		j++;
	}
	tab = ascii_time_path(tab, v);
	return (tab);
}

char	**ascii_multi_path(char **files, t_var *v)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (files[i])
	{
		while (files[j])
		{
			if (ft_strcmp(files[i], files[j]) < 0)
			{
				tmp = files[i];
				files[i] = files[j];
				files[j] = tmp;
			}
			j++;
		}
		if (v->len_n < ft_strlen(files[i]))
			v->len_n = ft_strlen(files[i]);
		i++;
		j = 0;
	}
	return (files);
}

void	multi_file(t_var *v, t_flags *f)
{
	int i;

	i = 0;
	if (v->index_f != 0)
	{
		padding_file(v->files, v);
		if (f->t == 1)
			time_multi_path(v->files, v);
		else
			ascii_multi_path(v->files, v);
		if (f->r == 1)
			rev_order(v->files);
		while (v->files[i])
		{
			free(v->first);
			v->first = ft_strdupt(v->files[i], v);
			if (f->l == 1)
				print_long(v);
			else
				print(v);
			i++;
		}
		free(v->first);
	}
}

int		multi_path(t_var *v, t_flags *f)
{
	int i;

	i = 0;
	multi_file(v, f);
	if (v->index_d != 0)
	{
		if (f->t == 1 && v->index_d > 2)
			time_multi_path(v->directory, v);
		else
			ascii_multi_path(v->directory, v);
		if (f->r == 1)
			rev_order(v->directory);
		while (v->directory[i])
		{
			v->path = v->directory[i];
			if (f->rec == 1)
				ft_recursive_flag(v->path, f, v);
			else
			{
				if (v->index_f != 0 || i != 0)
					ft_printf("\n");
				if (i > 0 && f->l == 0)
					ft_printf("\n");
				if (v->index_f != 0 || i != 0 || v->index_d != 1)
					ft_printf("%s:\n", v->directory[i]);
				print_ls(v, f);
			}
			i++;
		}
	}
	if (f->t == 1)
		free(v->mid);
	free_multi_path(v);
	return (0);
}
