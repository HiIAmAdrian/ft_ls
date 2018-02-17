/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:25:10 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:39:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	help_citire(char *arg, t_opt opt, t_size size, DIR *dir)
{
	char	*fullpath;
	t_nod	*start;

	fullpath = (char *)ft_memalloc(sizeof(fullpath) *
			(strlen(arg) + 2));
	strcpy(fullpath, arg);
	fullpath[ft_strlen(arg)] = '/';
	fullpath[ft_strlen(arg) + 1] = 0;
	start = ((opt.a == 1) ? citire_folder_cu_a(dir, fullpath, opt) :
			citire_folder_fara_a(dir, fullpath, opt));
	mainafis(opt, start, size);
}

void	copy_nod(t_nod **a, t_nod *b)
{
	(*a)->owner = b->owner;
	(*a)->group = b->group;
	(*a)->name = b->name;
	(*a)->calendar = b->calendar;
	(*a)->st_mode = b->st_mode;
	(*a)->path = b->path;
	(*a)->date = b->date;
	(*a)->st_nlink = b->st_nlink;
	(*a)->st_uid = b->st_uid;
	(*a)->st_gid = b->st_gid;
	(*a)->st_size = b->st_size;
	(*a)->st_blocks = b->st_blocks;
	(*a)->permissions = b->permissions;
}

t_nod	*eror(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	exit(EXIT_FAILURE);
}

void	ajut_afisare_ll(t_nod *list)
{
	ft_putnbr(list->st_size);
	ft_putchar(' ');
	ft_putstr(list->calendar);
	ft_putchar(' ');
	ft_putcolor(list);
	ft_putchar('\n');
}
