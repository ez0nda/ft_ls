/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:38:57 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/22 16:48:39 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_ls.h"

struct dirent	*diread;
struct stat		st;
struct tm		*date;

typedef struct		s_var
{
	DIR		*dir;
	char	*path;
	char	invalid;
	int		file_path;
	int		c_dir;
	char	**directory;
	int		index_d;
	char	**files;
	int		index_f;
	char	**file_in_dir;
	int		index_n;
	char	*first;
	char	*last;
	char	*mid;
	int		len_n;
	int		len;
	int		is_link;
}					t_var;

typedef struct		s_flags
{
	int opt_end;
	int mod;
	int l;
	int R;
	int a;
	int r;
	int t;
}					t_flags;

#endif
