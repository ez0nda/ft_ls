#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include "../libft/libft.h"

void	ft_stock(char *path, char **stock)
{
	DIR				*dir;
	struct dirent	*diread;
	int i = 0;

	dir = opendir(path);
	while ((diread = readdir(dir)) != NULL)
	{
		if (diread->d_name[0] == '.')
			continue ;
		stock[i] = ft_strdup(diread->d_name);
		i++;
	}
	stock[i] = NULL;
	closedir(dir);
}

void	print_name(char *path)
{
	DIR				*dir;
	struct dirent	*diread;

	dir = opendir(path);
	while ((diread = readdir(dir)) != NULL)
	{
		if (diread->d_name[0] == '.')
			continue ;
		printf("%s  ", diread->d_name);
	}
	closedir(dir);
}

void	recursive(char *str)
{
	struct stat		st;
	char *stock[50];
	int i = 0;

	ft_stock(str, stock);
	/*	while (stock[i])
		{
		printf("--%s--\n", stock[i]);
		i++;
		}*/
	printf("%s:\n", str);
	print_name(str);
	printf("\n\n");
	while (stock[i])
	{
//		printf("%s  ", stock[i]);
		if (stat(ft_strjoin(str, stock[i]), &st) < 0)
			return ;
		if (S_ISDIR(st.st_mode))
		{
		//	printf("--%s\n", ft_strjoin(str, ft_strjoin(stock[i], "/")));
			recursive(ft_strjoin(str, ft_strjoin(stock[i], "/")));
		}
		i++;
	}
	//print_name(str);
}

int		main(int ac, char **av)
{
	recursive("./");
	return (0);
}
