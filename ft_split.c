/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <goliano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:07:11 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/10 17:44:14 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char del)
{
	int		c;
	int		flag;

	c = 0;
	flag = 1;
	while (*s != '\0')
	{
		if (*s != del)
			flag = 0;
		if (*s == del && flag == 0)
		{
			flag = 1;
			c++;
		}
		s++;
	}
	if (*(s - 1) != del)
		c++;
	return (c);
}

static char	*split_word(char const *s, char del, int i)
{
	int		aux;
	int		r;
	char	*word;
	int		l;

	aux = i;
	l = 0;
	r = 0;
	while (s[i] != del && s[i] != '\0')
	{
		i++;
		l++;
	}
	word = (char *)malloc(sizeof(char) * (l + 1));
	if (!word)
		return (NULL);
	while (s[aux] != '\0' && r < l)
	{
		word[r] = s[aux];
		r++;
		aux++;
	}
	word[r] = '\0';
	return (word);
}

static void	fill_split(char const *s, char **str, char c)
{
	int	i;
	int	flag;
	int	r;

	i = 0;
	flag = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			str[r] = split_word(s, c, i);
			flag = 1;
			r++;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	str[r] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**str;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (w + 1));
	if (!str)
		return (NULL);
	fill_split(s, str, c);
	return (str);
}
