/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:07:16 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 14:51:14 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_size	owgr_size(t_nod *list, t_size size)
{
	if (getpwuid(list->st_uid))
		size.owner = ((int)ft_strlen(list->owner) > size.owner ?
				(int)ft_strlen(list->owner) : size.owner);
	else
		size.owner = ((int)ft_strlen(ft_itoa(list->st_uid)) > size.owner ?
				(int)ft_strlen(ft_itoa(list->st_uid)) : size.owner);
	if (getgrgid(list->st_gid))
		size.group = ((int)ft_strlen(list->group) > size.group ?
				(int)ft_strlen(list->group) : size.group);
	else
		size.group = ((int)ft_strlen(ft_itoa(list->st_gid)) > size.group ?
				(int)ft_strlen(ft_itoa(list->st_gid)) : size.group);
	size.nlink = ((int)ft_strlen(ft_itoa((int)list->st_nlink)) > size.nlink ?
			(int)ft_strlen(ft_itoa((int)list->st_nlink)) : size.nlink);
	size.marime = ((int)ft_strlen(ft_itoa((int)list->st_size)) > size.marime ?
			(int)ft_strlen(ft_itoa((int)list->st_size)) : size.marime);
	size.total += list->st_blocks;
	return (size);
}

void	d(t_opt opt, t_nod *list, t_size size)
{
	t_nod *start;

	start = list;
	while (list)
	{
		size = owgr_size(list, size);
		list = list->next;
	}
	afisare_l(opt, start, size);
}
