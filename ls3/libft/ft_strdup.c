/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <gmadec@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 00:36:38 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/18 15:53:30 by ezonda           ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = -1;
	dest = NULL;
	if (!s1)
		return (NULL);
	if (!(dest = ft_strnew(ft_strlen(s1))))
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	return (dest);
}
