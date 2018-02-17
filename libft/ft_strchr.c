/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:23:19 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 12:09:47 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*oana;

	i = 0;
	oana = (char *)str;
	while (oana[i])
	{
		if (oana[i] == c)
			return (&oana[i]);
		i++;
	}
	if (oana[i] == c)
		return (&oana[i]);
	return (NULL);
}
