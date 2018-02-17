/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:48:59 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 18:15:27 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	f_s(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 && s2)
	{
		if ((s3 = (char *)malloc(f_s(s1) + f_s(s2))))
		{
			while (s1[i])
			{
				s3[i] = s1[i];
				i++;
			}
			j = 0;
			while (s2[j])
				s3[i++] = s2[j++];
			s3[i] = 0;
			return (s3);
		}
	}
	return (NULL);
}
