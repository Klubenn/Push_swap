/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:05:41 by gtristan          #+#    #+#             */
/*   Updated: 2020/05/19 15:22:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static void	animation1(t_ps_str *st, int zero_a, int zero_b)
{
	char	*str;

	str = "------------------------------------------------------------";
	if (zero_a)
	{
		if (st->anim_a->num <= st->len / 3)
			ft_printf("{cyan}%-70.*s{eoc}", st->anim_a->num, str);
		else if (st->anim_a->num <= st->len * 2 / 3)
			ft_printf("{yellow}%-70.*s{eoc}", st->anim_a->num, str);
		else
			ft_printf("{red}%-70.*s{eoc}", st->anim_a->num, str);
	}
	else if (!zero_a && zero_b)
		ft_printf("%-70s", " ");
	if (zero_b)
	{
		if (st->anim_b->num <= st->len / 3)
			ft_printf("{cyan}%-70.*s{eoc}", st->anim_b->num, str);
		else if (st->anim_b->num <= st->len * 2 / 3)
			ft_printf("{yellow}%-70.*s{eoc}", st->anim_b->num, str);
		else
			ft_printf("{red}%-70.*s{eoc}", st->anim_b->num, str);
	}
	ft_putchar('\n');
}

void		animation(t_ps_str *st)
{
	int		zero_a;
	int		zero_b;

	st->anim_a = st->a;
	st->anim_b = st->b;
	zero_a = 0;
	if (st->a)
		zero_a = st->anim_a->prev->num;
	zero_b = 0;
	if (st->b)
		zero_b = st->anim_b->prev->num;
	ft_putstr(CLEAN);
	while (zero_a || zero_b)
	{
		animation1(st, zero_a, zero_b);
		if (st->anim_a && st->anim_a->num == zero_a)
			zero_a = 0;
		if (st->anim_b && st->anim_b->num == zero_b)
			zero_b = 0;
		if (st->anim_a)
			st->anim_a = st->anim_a->next;
		if (st->anim_b)
			st->anim_b = st->anim_b->next;
	}
	usleep(100000);
}
