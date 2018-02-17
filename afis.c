/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:40:13 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:39:27 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mainafis(t_opt opt, t_nod *start, t_size size)
{
	start = do_sorting(opt, start);
	((opt.l || opt.g) || (opt.l && opt.g)) ?
		d(opt, start, size) : display(start);
	opt.ur == 1 ? recursive(start, opt) : NULL;
}

void	afisare_ll(t_opt opt, t_nod *list, t_size size)
{
	ft_putstr(list->permissions);
	ft_strlen(list->permissions) == 11 ? ft_putstr(" ") : ft_putstr("  ");
	put_spaces((int)ft_strlen(ft_itoa(list->st_nlink)), size.nlink);
	ft_putnbr(list->st_nlink);
	ft_putchar(' ');
	if (!opt.g)
	{
		if (list->owner != NULL)
			ft_putstr(list->owner);
		else
			ft_putnbr(list->st_uid);
		put_spaces((int)ft_strlen(list->owner), size.owner);
		ft_putstr("  ");
	}
	if (list->group != NULL)
		ft_putstr(list->group);
	else
		ft_putnbr(list->st_uid);
	put_spaces((int)ft_strlen(list->group), size.group);
	ft_putstr("  ");
	put_spaces((int)ft_strlen(ft_itoa(list->st_size)), size.marime);
	ajut_afisare_ll(list);
}

void	afis_d(t_opt opt, char **argv, int i, t_size size)
{
	DIR		*dir;
	int		primu;
	t_nod	*list;
	t_nod	*start;

	primu = 0;
	while (argv[i])
	{
		if ((dir = opendir(argv[i])))
			if (!primu)
			{
				primu = 1;
				list = lstnew(opt, argv[i], argv[i]);
				start = list;
			}
			else
			{
				list->next = lstnew(opt, argv[i], argv[i]);
				list = list->next;
			}
		else
			eror(argv[i]);
		i++;
	}
	mainafis(opt, start, size);
}

void	afis_d_solo(t_opt opt, t_size size, char *path)
{
	t_nod	*list;
	t_nod	*start;
	DIR		*dir;

	start = NULL;
	list = NULL;
	if ((dir = opendir(path)))
	{
		list = lstnew(opt, path, path);
		start = list;
	}
	else
		eror(path);
	((opt.l || opt.g) || (opt.l && opt.g)) ?
		d(opt, start, size) : display(start);
}

void	afisare_l(t_opt opt, t_nod *list, t_size size)
{
	if (list)
	{
		ft_putstr("total:");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (list)
	{
		afisare_ll(opt, list, size);
		list = list->next;
	}
}
