/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:07:09 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:04:16 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strle(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	if ((copy = (char *)malloc((ft_strle(s1) + 1) * sizeof(char))))
	{
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = 0;
		return (copy);
	}
	return (NULL);
}
