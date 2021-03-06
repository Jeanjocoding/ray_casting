/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:27:36 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/26 15:26:43 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	word_counter(char const *str, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			count++;
		}
		if (i < ft_strlen(str))
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char			**stab_maker(size_t len)
{
	char			**stab;
	unsigned int	i;

	i = 0;
	if (!(stab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		stab[i] = 0;
		i++;
	}
	stab[i] = 0;
	return (stab);
}

static char			*s_extractor(char const *s, char c, unsigned int index)
{
	char			*mlc;
	unsigned int	i;
	unsigned int	start;

	i = 0;
//	if (s[index] == c)
//		index++;
//	ft_printf("\n\n-------------- new_turn --------------\n");
//	ft_printf("\n*s in extract : %s\n", &(s[index]));
//	index++;
	start = index;
	if (s[index] == c)
		return (ft_strdup(" "));
	while (s[index] && s[index] != c)
		index++;
//	if (s[index] == c)
//		index++;
	if (!(mlc = ft_strnew(index - start + 2)))
		return (NULL);
	while (s[start] && s[start] != c)
	{
		mlc[i] = s[start];
		i++;
		start++;
	}
	if (s[start] == c)
		mlc[i++] = ' ';
	mlc[i] = '\0';
//	ft_printf("mlc end extract %s\n", mlc);
//	ft_printf("-------------- end of turn --------------\n");
	return (mlc);
}

static char			**free_tab(char **tab, int k)
{
	while (--k >= 0)
		ft_strdel(&tab[k]);
	free(tab);
	return (NULL);
}

char				**ft_cub_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = stab_maker(word_counter(s, c))))
		return (NULL);
	while (s[i])
	{
//		while (s[i] == c)
//			i++;
		if (i < ft_strlen(s))
		{
			if (!(tab[k] = s_extractor(s, c, i)))
				return (free_tab(tab, k));
			i = i + ft_strlen(tab[k]);
			k++;
		}
	}
	tab[k] = 0;
	return (tab);
}
