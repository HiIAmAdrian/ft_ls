/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:40:42 by adstan            #+#    #+#             */
/*   Updated: 2017/12/12 17:58:16 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_utchar(char c)
{
	write(1, &c, 1);
	return (0);
}

static void		specialcase(void)
{
	ft_utchar('-');
	ft_utchar('2');
	ft_utchar('1');
	ft_utchar('4');
	ft_utchar('7');
	ft_utchar('4');
	ft_utchar('8');
	ft_utchar('3');
	ft_utchar('6');
	ft_utchar('4');
	ft_utchar('8');
}

static void		idk(int nb)
{
	if (!nb)
	{
		ft_utchar('0');
		return ;
	}
	if (nb == -2147483648)
	{
		specialcase();
		return ;
	}
}

void			ft_putnbr(int nb)
{
	char	v[12];
	int		i;

	i = 0;
	if (!nb || nb == -2147483648)
	{
		idk(nb);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_utchar('-');
	}
	while (nb)
	{
		v[i++] = nb % 10;
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_utchar(v[i--] + '0');
}
