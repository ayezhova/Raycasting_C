/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:17:31 by ayezhova          #+#    #+#             */
/*   Updated: 2019/10/02 23:23:38 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_word(char *array, char const *s, int cur, int wrd_len)
{
	int i;

	i = 0;
	while (i < wrd_len)
	{
		array[i] = s[cur + i];
		i++;
	}
	array[i] = '\0';
}

static int	count_letters(char const *s, int current_let, char c)
{
	int word_len;

	word_len = 0;
	while (s[current_let + word_len] != '\0' && s[current_let + word_len] != c)
	{
		word_len++;
	}
	return (word_len);
}

static int	word_counter(char const *s, char c)
{
	int num_words;
	int i;

	num_words = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		num_words++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			num_words++;
		i++;
	}
	return (num_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arrays;
	int		num_words;
	int		i_words;
	int		current_letter;
	int		word_length;

	if (!s)
		return (NULL);
	i_words = 0;
	num_words = word_counter(s, c);
	current_letter = 0;
	if (!(arrays = (char**)malloc(sizeof(char *) * num_words + 1)))
		return (NULL);
	while (i_words < num_words)
	{
		while (s[current_letter] == c)
			current_letter++;
		word_length = count_letters(s, current_letter, c);
		arrays[i_words] = (char*)malloc(sizeof(*arrays) * word_length + 1);
		add_word(arrays[i_words], s, current_letter, word_length);
		i_words++;
		current_letter += word_length;
	}
	arrays[i_words] = NULL;
	return (arrays);
}
