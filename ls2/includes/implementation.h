/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:43:07 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/01 15:46:55 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPLEMENTATION_H
# define IMPLEMENTATION_H

# include "struct.h"

void	ft_check_flag(int nb, char **av, t_flags *flag, t_var *v);
void	ft_initialize(t_flags *flag, t_var *v, char **av);
void	ft_usage(t_var *v, char *str, int mod);
void	ft_display(t_flags *flag, t_var *var);
void	ft_display_long(t_flags *flag, t_var *var);
void	ft_display_std(t_flags *flag, t_var *var);
void	ft_display_type(t_var *v);
void	ft_display_rights(void);
void	ft_display_usr_grp(void);
void	ft_display_time(void);
int		ft_ls_no_flag(t_var *v, t_flags *f);
void	ft_print_name(struct dirent diread, t_var *v);
void	ft_recursive_flag(char *str, t_flags *flag, t_var *v);
int		ft_nbrlen(int nb);
int		ft_count_blocks(t_var *v);
void	init_len_n_last(t_var *v, t_flags *f);
void	ascii_order(t_var *v, t_flags *f);
void	ft_print(t_var *v, t_flags *f);
int		count_lenf(int nb);
void	init_rev(t_var *v, t_flags *f);
void	ascii_rev(t_var *v);
void	ascii_init(t_var *v, int ac);
int		is_directory(char *str, t_var *v);
void	initialize_stock_dir(t_var *v);
void	print_multi_file(char *path, t_var *v, t_flags *f);
void	stock_dir(char *str, t_var *v);
void	ft_print_file_path(t_flags *flag, t_var *v);
void	display_multi(t_var *v, t_flags *f);
char	**rev_order(char **tab);
void	padding_multi(t_var *v);
void	init_last(t_var *v, int ac);
void	padding_initialisation(t_var *v);
void	init_flag_t(t_var *v, t_flags *f);
void	time_order(t_var *v, t_flags *f);
int		len_stock(t_var *v);
void	time_path(t_var *v, int ac);
int		cmp_time(time_t s1, time_t s2);
void	ascii_time_rev(t_var *v, char *s);
void	ascii_time(t_var *v, t_flags *f);
void	init_flag_t_r(t_var *v, t_flags *f);
void	algo_init_t(t_var *v, int i);
void	time_algo(t_var *v, int i);
void	ft_display_attr(t_var *v);

#endif
