/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:13:18 by adstan            #+#    #+#             */
/*   Updated: 2017/12/12 19:16:30 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		sari(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int		numar(char const *s, int i, char c)
{
	int nr;

	nr = 0;
	while (s[i] != c)
	{
		i++;
		nr++;
	}
	return (nr);
}

static int		numarcuvinte(char const *s, char c)
{
	int nr;
	int i;

	nr = 0;
	i = 1;
	if (s[0] != c)
		nr++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			nr++;
		i++;
	}
	return (nr);
}

static char		**ooop(char const *s, char c, int v[], char **tab)
{
	if (!(tab = (char **)malloc(sizeof(char*) * (v[1] + 1))))
		return (NULL);
	tab[v[1]] = 0;
	while (v[0] < v[1])
	{
		v[2] = sari(s, v[2], c);
		v[3] = numar(s, v[2], c);
		if (!(tab[v[0]] = (char*)malloc(v[3] + 1)))
			return (NULL);
		tab[v[0]++][v[3]] = 0;
		v[2] += v[3];
	}
	v[0] = 0;
	v[2] = 0;
	while (tab[v[0]])
	{
		v[1] = 0;
		v[2] = sari(s, v[2], c);
		v[3] = numar(s, v[2], c);
		while (v[1] < v[3])
			tab[v[0]][v[1]++] = s[v[2]++];
		tab[v[0]++][v[1]] = 0;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		v[4];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	if (!s[0])
	{
		if ((tab = (char**)malloc(sizeof(char*))))
		{
			tab[0] = 0;
			return (tab);
		}
		else
			return (NULL);
	}
	v[1] = numarcuvinte(s, c);
	return (ooop(s, c, v, tab));
}
