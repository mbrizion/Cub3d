/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:23:52 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/13 16:24:28 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char charset)
{
	return (c == charset) ? 1 : 0;
}

int		count_words(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	*get_word(int index, char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			if (count == index)
				return (&str[i]);
		}
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (NULL);
}

char	*alloc_word(char *word, char charset)
{
	int		i;
	char	*new_word;

	i = 0;
	while (word[i] && !is_in_charset(word[i], charset))
		i++;
	if (!(new_word = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (word[i] && !is_in_charset(word[i], charset))
	{
		new_word[i] = word[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;
	int		i;
	char	*buf;

	if (!s)
		return (0);
	buf = (char *)s;
	word_count = count_words(buf, c);
	if (!(words = malloc(sizeof(char*) * (word_count + 1))))
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		if (!(words[i] = alloc_word(get_word(i + 1, buf, c), c)))
			return (0);
		i++;
	}
	words[i] = NULL;
	return (words);
}
