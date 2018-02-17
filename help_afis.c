/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_afis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:47:11 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:17:01 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putcolor(t_nod *list)
{
	if (list->permissions[0] == 'd')
		ft_putstr("\033[1m\x1b[36m");
	else if (list->permissions[0] == 'l')
		ft_putstr("\x1b[35m");
	else if (list->permissions[0] == 's')
		ft_putstr("\x1b[32m");
	else if (list->permissions[0] == 'p')
		ft_putstr("\x1b[33m");
	else if (S_IEXEC & list->st_mode)
		ft_putstr("\x1b[31m");
	else if (list->permissions[0] == 'b')
		ft_putstr("\x1b[31m");
	else if (list->permissions[0] == 'c')
		ft_putstr("\x1b[34m");
	else if ((list->permissions[3] == 's' || list->permissions[6] == 's') ||
			(list->permissions[3] == 's' && list->permissions[3] == 's'))
		ft_putstr("\x1b[30m\x1b[43m");
	ft_putstr(list->name);
	ft_putstr("\x1b[0m");
}

void	put_spaces(int nr, int max)
{
	int i;

	i = max - nr;
	while (i-- > 0)
		ft_putchar(' ');
}

void	display(t_nod *start)
{
	while (start)
	{
		ft_putcolor(start);
		ft_putchar('\n');
		start = start->next;
	}
}
