/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:21:41 by ezonda            #+#    #+#             */
/*   Updated: 2019/02/05 13:57:47 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

# include "../libft/libft.h"

typedef struct s_flags
{
	int l;
	int R;
	int a;
	int r;
	int t;
	char invalid;
	char *path;
	char *path_end;
}				t_flags;

void	ft_check_flag(int nb, char **av, t_flags *flag);
void	ft_initialize(t_flags *flag);
void	ft_usage(t_flags *flag, char *str, int mod);

#endif
