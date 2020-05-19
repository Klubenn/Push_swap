/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:27 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:51:31 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_processing.h"
#include "ps_shared.h"

void		ret_big(t_ps_str *st)
{
	int step;

	step = st->max - 1;
	while (step > st->mid)
		step = sorting(&(st->a), &(st->b), step);
	rotate(&(st->a), 1, 'a');
	step--;
	while (st->b)
		step = sorting(&(st->a), &(st->b), step);
}

static int	rem_big1(t_ps_str *st, int low, int high, int *tmp)
{
	int i;

	i = 0;
	if (st->a->num > low && st->a->num != st->mid && st->a->num < high)
	{
		i++;
		push(&(st->b), &(st->a), 'b');
		if (st->b->num < st->mid)
		{
			if (st->a->num >= high || st->a->num <= low ||
				st->a->num == st->mid)
			{
				ro_rotate(&(st->a), &(st->b), 0);
				(*tmp)--;
			}
			else
				rotate(&(st->b), 0, 'b');
		}
	}
	else
		rotate(&(st->a), 0, 'a');
	(*tmp)--;
	return (i);
}

int			rem_big(t_ps_str *st, int step)
{
	int high;
	int low;
	int i;
	int tmp;

	i = 0;
	tmp = st->len;
	high = st->max * (st->steps * 2 - step) / (st->steps * 2);
	low = st->max * step / (st->steps * 2);
	if (step == 0)
		low = 1;
	while (tmp > 0)
		i += rem_big1(st, low, high, &tmp);
	return (i);
}

void		big(t_ps_str *st)
{
	int step;

	st->steps = 10;
	if (st->len <= 100)
		st->steps = 2;
	step = st->steps;
	while (--step >= 0)
		st->len -= rem_big(st, step);
	st->mix = check_sort(st->a);
	three(st);
	rotate(&(st->a), 1, 'a');
	ret_big(st);
	rotate(&(st->a), 1, 'a');
}

void		ten(t_ps_str *st)
{
	int i;

	i = 0;
	while (i++ < st->len)
	{
		if (st->a->num != 1 && st->a->num != st->mid && st->a->num != st->len)
			push(&(st->b), &(st->a), 'b');
		else
			rotate(&(st->a), 0, 'a');
	}
	st->mix = check_sort(st->a);
	three(st);
	rotate(&(st->a), 1, 'a');
	ret_big(st);
	rotate(&(st->a), 1, 'a');
}
