/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:42:18 by adstan            #+#    #+#             */
/*   Updated: 2018/02/11 17:52:00 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nod	*do_sorting(t_opt opt, t_nod *start)
{
	t_nod *abc;

	abc = start;
	if (!opt.f)
		sort_alpha(&abc);
	if (opt.t)
		sort_t(&abc);
	if (opt.r)
		sort_r(&abc);
	return (abc);
}

void	swap_nods(t_nod **a, t_nod **b)
{
	t_nod c;

	c = **b;
	copy_nod(b, *a);
	copy_nod(a, &c);
}

void	sort_alpha(t_nod **list)
{
	t_nod *a;
	t_nod *b;

	b = (*list);
	while (b)
	{
		a = b->next;
		while (a)
		{
			if (ft_strcmp(b->name, a->name) > 0)
				swap_nods(&b, &a);
			a = a->next;
		}
		b = b->next;
	}
}

void	sort_r(t_nod **list)
{
	t_nod *a;
	t_nod *b;
	t_nod *c;

	a = (*list);
	c = NULL;
	while (a)
	{
		b = c;
		c = a;
		a = a->next;
		c->next = b;
	}
	(*list) = c;
}

void	sort_t(t_nod **list)
{
	t_nod *a;
	t_nod *b;

	b = (*list);
	while (b)
	{
		a = b->next;
		while (a)
		{
			if (ft_strcmp(ft_itoa((int)b->date), ft_itoa((int)a->date)) < 0)
				swap_nods(&b, &a);
			a = a->next;
		}
		b = b->next;
	}
}
