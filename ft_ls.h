/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:53:07 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 18:02:54 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include "./libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct		s_opt
{
	int				l;
	int				ur;
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
	int				d;
}					t_opt;

typedef struct		s_nod
{
	char			*owner;
	char			*group;
	char			*name;
	char			*calendar;
	mode_t			st_mode;
	char			*path;
	time_t			date;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	long long		total;
	char			*permissions;
	struct s_nod	*next;
}					t_nod;

typedef struct		s_size
{
	int				total;
	int				nlink;
	int				owner;
	int				group;
	int				marime;
}					t_size;

void				printusage(char c);
void				initialize_arg(char c);
int					oneof(char *str);
int					parsare(int argc, char **argv);
int					main(int argc, char **argv);
void				citire_fiecare_folder(char
		**argv, t_opt opt, int i, t_size size);
t_nod				*citire_folder_cu_a(DIR *dir, char *fullpath, t_opt opt);
t_nod				*citire_folder_fara_a(DIR *dir, char *fullpath, t_opt opt);
t_nod				*eror(char *name);
void				f_groupname(t_nod *list);
void				f_date(t_nod *list);
t_nod				*do_sorting(t_opt opt, t_nod *start);
void				copy_nod(t_nod **a, t_nod *b);
void				swap_nods(t_nod **a, t_nod **b);
void				sort_alpha(t_nod **list);
void				sort_r(t_nod **list);
void				sort_t(t_nod **list);
void				reading_one_folder(char *path, t_opt opt, t_size size);
void				display(t_nod *start);
t_size				owgr_size(t_nod *list, t_size size);
void				afisare_l(t_opt opt, t_nod *list, t_size size);
void				d(t_opt opt, t_nod *list, t_size size);
void				afisare_ll(t_opt opt, t_nod *list, t_size size);
void				afis_d(t_opt opt, char **argv, int i, t_size size);
void				ft_putcolor(t_nod *list);
t_nod				*lstnew(t_opt opt, char *fullpath, char *ret);
void				afis_d_solo(t_opt opt, t_size size, char *path);
void				mainafis(t_opt opt, t_nod *start, t_size size);
void				recursive(t_nod *list, t_opt opt);
void				f_acl(t_nod *list);
void				help_citire(char *arg, t_opt opt, t_size size, DIR *dir);
void				f_permis2(struct stat st, t_nod **list);
void				f_permis(struct stat st, t_nod **list);
void				ajut_afisare_ll(t_nod *list);
void				afisare_ll(t_opt opt, t_nod *list, t_size size);
void				put_spaces(int nr, int max);

#endif
