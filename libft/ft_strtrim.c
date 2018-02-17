/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:07:53 by adstan            #+#    #+#             */
/*   Updated: 2018/01/07 15:14:07 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_s(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	functie(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	sf(char const *s)
{
	int i;

	i = ft_s(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*c;
	int		inceput;
	int		sfarsit;
	int		size;

	if (s)
	{
		inceput = functie(s);
		sfarsit = sf(s);
		size = sfarsit - inceput;
		if (size < 1)
			size = 1;
		if ((c = (char *)malloc(size + 2)))
		{
			i = 0;
			while (inceput <= sfarsit)
				c[i++] = s[inceput++];
			c[i] = 0;
			return (c);
		}
	}
	return (NULL);
}
