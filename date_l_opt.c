/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_l_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:51:52 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 16:30:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	f_permis(struct stat st, t_nod **list)
{
	(*list)->permissions = (char*)malloc(sizeof(char) * 12);
	if ((S_ISDIR(st.st_mode)))
		(*list)->permissions[0] = 'd';
	else if ((S_ISLNK(st.st_mode)))
		(*list)->permissions[0] = 'l';
	else if ((S_ISBLK(st.st_mode)))
		(*list)->permissions[0] = 'b';
	else if ((S_ISCHR(st.st_mode)))
		(*list)->permissions[0] = 'c';
	else if ((S_ISFIFO(st.st_mode)))
		(*list)->permissions[0] = 'p';
	else if ((S_ISSOCK(st.st_mode)))
		(*list)->permissions[0] = 's';
	else
		(*list)->permissions[0] = '-';
	(*list)->permissions[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	(*list)->permissions[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	if ((st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID))
		(*list)->permissions[3] = 's';
	else if (!(st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID))
		(*list)->permissions[3] = 'S';
	else if ((st.st_mode & S_IXUSR))
		(*list)->permissions[3] = 'x';
	else
		(*list)->permissions[3] = '-';
}

void	f_permis2(struct stat st, t_nod **list)
{
	(*list)->permissions[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	(*list)->permissions[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	if ((st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID))
		(*list)->permissions[6] = 's';
	else if (!(st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID))
		(*list)->permissions[6] = 'S';
	else if ((st.st_mode & S_IXGRP))
		(*list)->permissions[6] = 'x';
	else
		(*list)->permissions[6] = '-';
	(*list)->permissions[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	(*list)->permissions[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	if ((st.st_mode & S_IXOTH) && (st.st_mode & S_ISVTX))
		(*list)->permissions[9] = 't';
	else if (!(st.st_mode & S_IXOTH) && (st.st_mode & S_ISVTX))
		(*list)->permissions[9] = 'T';
	else if ((st.st_mode & S_IXOTH))
		(*list)->permissions[9] = 'x';
	else
		(*list)->permissions[9] = '-';
	(*list)->permissions[10] = 0;
}

void	f_acl(t_nod *list)
{
	ssize_t		xattr;
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	xattr = listxattr(list->path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_link_np(list->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (xattr > 0)
	{
		list->permissions[11] = 0;
		list->permissions[10] = '@';
	}
	else if (acl != NULL)
	{
		list->permissions[11] = 0;
		list->permissions[10] = '+';
	}
}

void	f_groupname(t_nod *list)
{
	struct passwd	*pw;
	struct group	*gr;

	f_acl(list);
	f_date(list);
	pw = getpwuid(list->st_uid);
	gr = getgrgid(list->st_gid);
	if (pw)
		list->owner = strdup(pw->pw_name);
	else
		list->owner = NULL;
	if (gr)
		list->group = strdup(gr->gr_name);
	else
		list->group = NULL;
}

void	f_date(t_nod *list)
{
	time_t	actualtime;
	char	*data;
	char	*copy;

	if (!(actualtime = time(0)))
		eror(list->name);
	if (!(data = ctime(&list->date)))
		eror(list->name);
	if ((actualtime - 15778463) > list->date || actualtime < list->date)
	{
		copy = ft_strsub(data, 20, 4);
		data = ft_strsub(data, 4, 6);
		data = ft_strjoin(data, "  ");
		data = ft_strjoin(data, copy);
	}
	else
		data = ft_strsub(data, 4, 12);
	data[12] = 0;
	list->calendar = data;
}
