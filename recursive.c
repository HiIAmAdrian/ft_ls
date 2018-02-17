/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:00:51 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 16:32:15 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	do_rec(char *path, t_opt opt)
{
	t_nod	*begin;
	t_size	siz;

	siz.total = 0;
	siz.nlink = 0;
	siz.owner = 0;
	siz.group = 0;
	siz.marime = 0;
	begin = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putchar('\n');
	reading_one_folder(path, opt, siz);
}

void	recursive(t_nod *list, t_opt opt)
{
	while (list)
	{
		if ((S_ISDIR(list->st_mode)) && ft_strcmp(list->name, ".") &&
				ft_strcmp(list->name, ".."))
			do_rec(list->path, opt);
		list = list->next;
	}
}
