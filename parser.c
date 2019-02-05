/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:28:46 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/05 15:21:08 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static char		*ft_get_path(char *str, t_flags *flag)
{
	int start;
	int end;

	start = 0;
	while (str[start])
		start++;
	end = start;
	while (str[start] != '/')
		start--;
	flag->path_end = ft_strsub(str, start + 1, end - start);
	return (ft_strsub(str, 0, start));
}

static int		ft_check_path(char *str, t_flags *flag)
{
	struct dirent	*diread;
	DIR				*dir;

	if ((dir = opendir(str)) == NULL && ft_strchr(str, '/') != NULL)
		dir = opendir(ft_get_path(str, flag));
	else if ((dir = opendir(str)) == NULL && ft_strchr(str, '/') == NULL)
	{
		dir = opendir(".");
		flag->path_end = str;
	}
	else
		return (ft_strlen(str));
	while ((diread = readdir(dir)) != NULL)
	{
		if (ft_strcmp(diread->d_name, flag->path_end) != 0)
			continue ;
		else if (ft_strcmp(diread->d_name, flag->path_end) == 0)
		{
			closedir(dir);
			return (ft_strlen(str));
		}
	}
	ft_usage(flag, str, 0);
	closedir(dir);
	exit(EXIT_FAILURE);
}

static int		ft_check_str(char *str, t_flags *flag)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' || str[i] == 'r'
				|| str[i] == 't')
			i++;
	}
	else
		i = ft_check_path(str, flag);
	if (i == ft_strlen(str))
		return (1);
	else
	{
		flag->invalid = str[i];
		ft_printf("bad 2\n\n");
		ft_usage(flag, str, 1);
	}
	return (0);
}

static void		ft_initialize_flag(char *str, t_flags *flag)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'l')
			flag->l = 1;
		if (str[i] == 'R')
			flag->R = 1;
		if (str[i] == 'a')
			flag->a = 1;
		if (str[i] == 'r')
			flag->r = 1;
		if (str[i] == 't')
			flag->t = 1;
		i++;
	}
}

void			ft_check_flag(int nb, char **av, t_flags *flag)
{
	int i;

	i = 1;
	while (i <= nb)
	{
		if (ft_check_str(av[i], flag) == 0)
			exit(EXIT_FAILURE);
		else
			ft_initialize_flag(av[i], flag);
		i++;
	}
}
