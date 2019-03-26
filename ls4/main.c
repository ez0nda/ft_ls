/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:15:36 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/26 13:46:04 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	malloc_path(t_var *v)
{
	if (!(v->files = (char**)malloc(sizeof(char*) * (v->index_f + 1))))
		exit(EXIT_FAILURE);
	if (!(v->directory = (char**)malloc(sizeof(char*) * (v->index_d + 1))))
		exit(EXIT_FAILURE);
	while (v->index_d > 0)
		v->directory[v->index_d--] = NULL;
	while (v->index_f > 0)
		v->files[v->index_f--] = NULL;
}

static void		initialize_path(t_var *v, char **av)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			tmp++;
			continue ;
		}
		if (av[i][0] == '-' && v->index_d == 0
				&& v->index_f == 0 && v->index_n == 0 && tmp == 0)
			continue ;
		if (is_directory(av[i], v) == 1)
			v->index_d++;
		else if (is_file(av[i], v) == 1)
			v->index_f++;
		else if (is_file_n(av[i], v) == 2)
			v->index_f++;
		else
			rm_av_t(av, i--);
	}
	malloc_path(v);
}

static int		initialize(t_var *v, t_flags *f, char **av, int ac)
{
	v->path = ft_strdup("./");
	v->first = NULL;
	v->last = NULL;
	v->len_n = 0;
	v->len = 0;
	v->index_f = 0;
	v->index_d = 0;
	v->index_n = 0;
	if (ac > 1)
		initialize_path(v, av);
	f->mod = 0;
	f->l = 0;
	f->t = 0;
	f->r = 0;
	f->a = 0;
	f->R = 0;
	return (0);
}

void		free_multi_path(t_var *v)
{
	int i;

	i = 0;
	while (i < v->index_f)
		free(v->files[i++]);
	free(v->files);
	i = 0;
	while (i < v->index_d)
		free(v->directory[i++]);
	free(v->directory);
}

int				main(int ac, char **av)
{
	t_var	v;
	t_flags	f;

	if (initialize(&v, &f, av, ac) == -1)
	{
		free(v.path);
		exit(EXIT_FAILURE);
	}
	if (ac == 1)
		return (print_ls(&v, &f));
	if (ac > 1)
		ft_check_flag(av, &f, &v);
	if (v.index_f == 0 && v.index_d == 0 && v.index_n == 0)
		free_multi_path(&v);
//	else
//		return (multi_path(&v));
	if (f.R == 1)
	{
		ft_recursive_flag(v.path, &f, &v);
		return (0);
	}
	return (print_ls(&v, &f));
}
