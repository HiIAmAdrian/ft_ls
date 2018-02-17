/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:30:52 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 18:00:44 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = start;
	j = 0;
	if (s)
	{
		if ((str = (char *)malloc(len + 1)))
		{
			while (j < len)
			{
				str[j] = s[i];
				i++;
				j++;
			}
			str[j] = 0;
			return (str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
