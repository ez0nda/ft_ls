/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:43:07 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/26 11:51:24 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLEMENTATION_H
# define IMPLEMENTATION_H

# include "struct.h"

void	ft_check_flag(char **av, t_flags *flag, t_var *v);
void	ft_usage(t_var *v, char *str, int mod);
int		invalid_case(char *str, size_t i, t_var *v);
void	rm_av_t(char **av, int index);
int		is_file(char *s, t_var *v);
int		is_file_n(char *s, t_var *v);
int		is_directory(char *s, t_var *v);

int		print_ls(t_var *v, t_flags *f);
int		init_print_t(t_var *v, t_flags *f);
int		print_ls_time(t_var *v, t_flags *f);
void	print_ls_ascii(t_var *v, t_flags *f);
void	new_alloc(t_var *v, struct dirent *diread, int mod);
int		print_long(t_var *v);

int		ft_count_blocks(t_var *v);
int		free_long(char *name, char *pathname, int mod);

void	ft_recursive_flag(char *str, t_flags *flag, t_var *v);

void	time_algo_rev(t_var *v);
int		time_rev(t_var *v, int i);
int		save_ascii_time(t_var *v, int i);
void	time_algo(t_var *v, int i);
void	ascii_time(t_var *v, t_flags *f);

int		multi_path(t_var *v);
void	free_multi_path(t_var *v);

#endif
