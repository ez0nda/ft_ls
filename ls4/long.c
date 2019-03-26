/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:03:52 by jebrocho          #+#    #+#             */
/*   Updated: 2019/03/26 11:50:40 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void		ft_display_type(t_var *v)
{
	if (S_ISDIR(st.st_mode))
		ft_printf("d");
	else if (S_ISCHR(st.st_mode))
		ft_printf("c");
	else if (S_ISBLK(st.st_mode))
		ft_printf("b");
	else if (S_ISLNK(st.st_mode))
	{
		ft_printf("l");
		v->is_link = 1;
	}
	else if (S_ISFIFO(st.st_mode))
		ft_printf("p");
	else if (S_ISSOCK(st.st_mode))
		ft_printf("s");
	else if (S_ISREG(st.st_mode))
		ft_printf("-");
}

static void		ft_display_rights(void)
{
	ft_printf((st.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((st.st_mode & S_IWUSR) ? "w" : "-");
	if (st.st_mode & S_IXUSR)
		ft_printf((st.st_mode & S_ISUID) ? "s" : "x");
	else if (st.st_mode & S_ISUID)
		ft_printf("S");
	else
		ft_printf("-");
	ft_printf((st.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((st.st_mode & S_IWGRP) ? "w" : "-");
	if (st.st_mode & S_IXGRP)
		ft_printf((st.st_mode & S_ISGID) ? "s" : "x");
	else if (st.st_mode & S_ISGID)
		ft_printf("S");
	else
		ft_printf("-");
	ft_printf((st.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((st.st_mode & S_IWOTH) ? "w" : "-");
	if (st.st_mode & S_IXOTH)
		ft_printf((st.st_mode & S_ISVTX) ? "t" : "x");
	else if (st.st_mode & S_ISVTX)
		ft_printf("T");
	else
		ft_printf("-");
}

static void		ft_display_usr_grp(void)
{
	struct passwd	*usr;
	struct group	*grp;

	usr = getpwuid(st.st_uid);
	if (usr != NULL)
		ft_printf(" %s", usr->pw_name);
	else
		ft_printf(" %ld", (long)st.st_uid);
	grp = getgrgid(st.st_gid);
	if (grp != NULL)
		ft_printf("  %s", grp->gr_name);
	else
		ft_printf("  %ld", (long)st.st_gid);
}

static void		ft_get_link(t_var *v, char *pathname)
{
	int			nbytes;
	char		buff[256];

	nbytes = readlink(pathname, buff, sizeof(buff));
	buff[nbytes] = '\0';
	ft_printf(" -> %s", buff);
	v->is_link = 0;
}

static void		ft_display_attr(t_var *v)
{
	char	*pathname;

	pathname = ft_strjoin(v->path, v->first);
	if (listxattr(pathname, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_printf("@");
	else
		ft_printf(" ");
	free(pathname);
}

int				print_long(t_var *v)
{
	char	*name;
	char	*pathname;
	char	*time;

	name = ft_strdup(v->first);
	pathname = ft_strjoin(v->path, name);
	if (stat(pathname, &st) < 0)
		return (free_long(name, pathname, 0));
	if (lstat(pathname, &st) < 0)
		return (free_long(name, pathname, 0));
	ft_display_type(v);
	ft_display_rights();
	ft_display_attr(v);
	ft_printf(" %d", st.st_nlink);
	ft_display_usr_grp();
	ft_printf(" %d", st.st_size);
	time = ft_strsub(ctime(&st.st_mtime), 4, 12);
	ft_printf(" %s ", time);
	free(time);
	ft_printf("%s", v->first);
	if (v->is_link == 1)
		ft_get_link(v, pathname);
	ft_printf("\n");
	return (free_long(name, pathname, 1));
}
