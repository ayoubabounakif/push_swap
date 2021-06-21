/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:04:17 by aabounak          #+#    #+#             */
/*   Updated: 2020/12/15 12:48:41 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wlen(char const *str, int i, int *nbword, int c)
{
	*nbword += 1;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	ft_fill(char **tab, char const *str, int *nbword, int c)
{
	int		wlen;
	int		j;
	char	*tmp;
	int		sv;

	wlen = 0;
	sv = 0;
	while (str[wlen] != c && str[wlen] != '\0')
		wlen++;
	tmp = (char *)malloc((wlen + 1) * sizeof(char));
	tmp[wlen] = '\0';
	j = 0;
	while (sv < wlen)
	{
		tmp[j] = str[sv++];
		j++;
	}
	tab[*nbword] = tmp;
	*nbword += 1;
	return (wlen);
}

void	ft_free_it(char **tab, int n)
{
	int	i;

	i = 0;
	while (i > n)
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**tab;
	int		number_words;

	reset(&i, &number_words);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		if (str[i] != c)
			i = ft_wlen(str, i, &number_words, c);
	else
		i++;
	tab = (char **)malloc((number_words + 1) * sizeof(char *));
	tab[number_words] = 0;
	reset(&i, &number_words);
	while (str[i] != '\0')
	{
		if (str[i] != c)
			i += ft_fill(tab, str + i, &number_words, c);
		else
			i++;
	}
	if (!number_words && !tab)
		return (NULL);
	return (tab);
}
