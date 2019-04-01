/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:43:07 by jebrocho          #+#    #+#             */
/*   Updated: 2019/04/01 18:15:06 by jebrocho         ###   ########.fr       */
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
char	*ft_dirchr(char *str, int c);

int		print_ls(t_var *v, t_flags *f);
void	print(t_var *v);
void	init_print_t(t_var *v, t_flags *f);
void	print_ls_time(t_var *v, t_flags *f);
void	print_ls_ascii(t_var *v, t_flags *f);
void	new_alloc(t_var *v, char *name, int mod);
int		print_long(t_var *v);

int		ft_count_blocks(t_var *v);

void	ft_recursive_flag(char *str, t_flags *flag, t_var *v);

void	time_algo_rev(t_var *v);
int		time_rev(t_var *v, int i);
int		save_ascii_time(t_var *v, int i, char *name);
void	time_algo(t_var *v, int i, char *name);
void	ascii_time(t_var *v, t_flags *f);
void	ft_display_time(char *time);
void	ft_display_dev(t_var *v);

int		multi_path(t_var *v, t_flags *f);
char	**rev_order(char **tab);
char	**ascii_multi_path(char **files, t_var *v);
char	**time_multi_path(char **tab, t_var *v);

char	**free_path_stat(char *s);
void	free_pathname(char *s1, char *s2);
int		free_pathname_int(char *s1, char *s2);
void	free_multi_path(t_var *v);
int		free_long(char *name, char *pathname, int mod);
int		nbrsize(int nb);
char	*ft_strdupt(char *s, t_var *v);
int		countlen(char *s);
void	padding_all(t_var *v);
void	padding_dev(t_var *v);

#endif
