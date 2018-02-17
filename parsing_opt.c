/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:51:21 by adstan            #+#    #+#             */
/*   Updated: 2018/02/13 17:30:05 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt g_opt = {0, 0, 0, 0, 0, 0, 0, 0, 0};
t_size g_size = {0, 0, 0, 0, 0};

void	printusage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("");
	ft_putendl("usage: ft_ls [-Rafglrtu1] [file ...]");
}

void	initialize_arg(char c)
{
	g_opt.a = ((c == 'a' || c == 'f') ? 1 : g_opt.a);
	g_opt.t = (c == 't' ? 2 : g_opt.t);
	g_opt.ur = (c == 'R' ? 1 : g_opt.ur);
	g_opt.u = (c == 'u' ? 1 : g_opt.u);
	g_opt.g = (c == 'g' ? 1 : g_opt.g);
	g_opt.d = (c == 'd' ? 1 : g_opt.d);
	g_opt.l = (c == 'l' ? 1 : g_opt.l);
	g_opt.r = (c == 'r' ? 1 : g_opt.r);
	g_opt.f = (c == 'f' ? 1 : g_opt.f);
	if (g_opt.d == 1)
		g_opt.ur = 0;
}

int		oneof(char *str)
{
	char	*options;
	int		i;

	options = strdup("ufgdlratR1");
	i = 1;
	while (str[i])
	{
		if (!(strchr(options, str[i])))
		{
			printusage(str[i]);
			return (0);
		}
		initialize_arg(str[i]);
		i++;
	}
	if (g_opt.f == 1)
	{
		g_opt.f = 1;
		g_opt.r = 0;
		g_opt.t = 0;
		g_opt.a = 1;
	}
	return (1);
}

int		parsare(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (!(oneof(argv[i])))
			return (-1);
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	int i;

	i = parsare(argc, argv);
	if (i < 0)
		return (0);
	if (argc - i > 1)
		citire_fiecare_folder(argv, g_opt, i, g_size);
	else if (argc - i == 1)
		reading_one_folder(argv[argc - 1], g_opt, g_size);
	else if (!argv[i])
		reading_one_folder(".", g_opt, g_size);
	return (0);
}
