/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:48:50 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 10:25:05 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c);
static void	find_next(char const *s, char c, size_t *index, size_t *length);
static void	dealloc(char **result, int cnt);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_num;
	size_t	i;
	size_t	word_start;
	size_t	word_length;

	i = -1;
	word_start = 0;
	word_length = 0;
	word_num = count_word(s, c);
	result = (char **)ft_calloc(word_num + 1, sizeof(char *));
	if (result == 0)
		return (0);
	while (++i < word_num)
	{
		find_next(s, c, &word_start, &word_length);
		result[i] = ft_substr(s, word_start, word_length);
		if (result[i] == 0)
		{
			dealloc(result, i);
			return (0);
		}
		word_start += word_length;
	}
	return (result);
}

static int	count_word(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static void	find_next(char const *s, char c, size_t *index, size_t *length)
{
	size_t	i;

	*length = 0;
	i = *index;
	while (s[i])
	{
		if (s[i] != c)
		{
			*index = i;
			break ;
		}
		i++;
	}
	while (s[i] && s[i] != c)
	{
		*length = *length + 1;
		i++;
	}
}

static void	dealloc(char **result, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		free(result[i]);
		i++;
	}
	free(result);
}
