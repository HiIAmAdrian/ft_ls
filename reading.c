/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:51:35 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:39:08 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nod	*lstnew(t_opt opt, char *fullpath, char *ret)
{
	t_nod		*list;
	struct stat	st;

	if (!(list = (t_nod *)ft_memalloc(sizeof(t_nod))))
		eror("");
	list->path = strdup(fullpath);
	list->name = strdup(ret);
	list->path[strlen(fullpath)] = 0;
	if (lstat(list->path, &st) == -1)
		eror(list->path);
	list->st_mode = st.st_mode;
	list->date = (opt.u == 1 ? st.st_atime : st.st_mtime);
	f_permis(st, &list);
	f_permis2(st, &list);
	if ((opt.l || opt.g) || (opt.l && opt.g))
	{
		list->st_nlink = st.st_nlink;
		list->st_uid = st.st_uid;
		list->st_gid = st.st_gid;
		list->st_size = st.st_size;
		list->st_blocks = st.st_blocks;
		f_groupname(list);
	}
	list->next = NULL;
	return (list);
}

t_nod	*citire_folder_cu_a(DIR *dir, char *fullpath, t_opt opt)
{
	struct dirent	*ret;
	t_nod			*list;
	t_nod			*start;
	char			*copy;

	start = NULL;
	if ((ret = readdir(dir)))
	{
		copy = fullpath;
		fullpath = ft_strjoin(fullpath, ret->d_name);
		list = lstnew(opt, fullpath, ret->d_name);
		fullpath = copy;
		start = list;
	}
	else
		return (eror(ret->d_name));
	while ((ret = readdir(dir)))
	{
		copy = fullpath;
		fullpath = ft_strjoin(fullpath, ret->d_name);
		list->next = lstnew(opt, fullpath, ret->d_name);
		list = list->next;
		fullpath = copy;
	}
	return (start);
}

t_nod	*citire_folder_fara_a(DIR *dir, char *fullpath, t_opt opt)
{
	struct dirent	*ret;
	t_nod			*list;
	t_nod			*start;
	int				primu;

	primu = 0;
	start = NULL;
	while ((ret = readdir(dir)))
	{
		if (ret->d_name[0] != '.' && !primu)
		{
			primu = 1;
			list = lstnew(opt, ft_strjoin(fullpath, ret->d_name), ret->d_name);
			start = list;
		}
		else if (ret->d_name[0] != '.')
		{
			list->next = lstnew(opt,
					ft_strjoin(fullpath, ret->d_name), ret->d_name);
			list = list->next;
		}
	}
	return (start);
}

void	reading_one_folder(char *path, t_opt opt, t_size size)
{
	DIR		*dir;
	char	*fullpath;
	t_nod	*start;

	dir = NULL;
	if (opt.d)
		afis_d_solo(opt, size, path);
	else
	{
		if ((dir = opendir(path)))
		{
			fullpath = (char *)
				ft_memalloc(sizeof(char) * (ft_strlen(path) + 2));
			ft_strcpy(fullpath, path);
			fullpath[ft_strlen(path)] = '/';
			fullpath[ft_strlen(path) + 1] = 0;
			start = ((opt.a == 1) ? citire_folder_cu_a(dir, fullpath, opt) :
					citire_folder_fara_a(dir, fullpath, opt));
			mainafis(opt, start, size);
		}
		else
			eror(path);
		if (closedir(dir) == -1)
			eror(path);
	}
}

void	citire_fiecare_folder(char **argv, t_opt opt, int i, t_size size)
{
	DIR		*dir;
	int		primu;

	primu = 0;
	if (opt.d)
		afis_d(opt, argv, i, size);
	else
		while (argv[i])
		{
			if ((dir = opendir(argv[i])))
			{
				if (primu)
					ft_putendl("");
				primu = 1;
				ft_putstr(argv[i]);
				ft_putendl(":");
				help_citire(argv[i], opt, size, dir);
			}
			else
				eror(argv[i]);
			if (closedir(dir) == -1)
				eror(argv[i]);
			i++;
		}
}
