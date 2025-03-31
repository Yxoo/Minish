/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorouger <jorouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:06:31 by jorouger          #+#    #+#             */
/*   Updated: 2025/03/26 13:36:19 by jorouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_wordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*ft_freeall(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	w_len;
	int		j;
	int		o;

	o = 0;
	res = ft_calloc(sizeof(char *), ft_count_word(s, c) + 1);
	if (!res)
		return (NULL);
	while (*s)
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		if (*s == 0)
			break ;
		w_len = ft_wordlen((char *)s, c);
		res[o] = ft_calloc(sizeof(char), w_len + 1);
		if (!res[o])
			return (ft_freeall(res));
		while (j < (int)w_len)
			res[o][j++] = *s++;
		o++;
	}
	return (res);
}
