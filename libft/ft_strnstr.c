/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:20:57 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/07 16:53:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

static int	check(const char *start_add, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_ind;

	h_ind = 0;
	if (needle == 0)
		return ((char *)haystack);
	while (h_ind < len && haystack[h_ind])
	{
		if (haystack[h_ind] == needle[0])
		{
			if (check(haystack + h_ind, needle, len - h_ind))
			{
				return ((char *)(haystack + h_ind));
			}
		}
		h_ind++;
	}
	return (0);
}

static int	check(const char *start_add, const char *needle, size_t len)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i <= len)
	{
		if (needle[i + 1] == 0)
		{
			flag = 1;
			break ;
		}
		if (start_add[i] != needle[i])
			break ;
		i++;
	}
	return (flag);
}

/*int main()
{
	printf("%s\n", ft_strnstr("My strnstr test strnstr", "str", 4));
}*/