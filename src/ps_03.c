/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:14 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:51:16 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_processing.h"
#include "ps_shared.h"

void		three(t_ps_str *st)
{
	while (1)
	{
		if (st->mix > 0)
		{
			if (st->a->num > st->a->next->num && st->a->num > st->a->prev->num)
				rotate(&(st->a), 0, 'a');
			else if (st->a->num < st->a->next->num && st->a->num >
					st->a->prev->num)
				rotate(&(st->a), 1, 'a');
			else
				swap(&(st->a), &(st->a->next), 'a');
		}
		else if (st->mix == 0)
			break ;
		st->mix = check_sort(st->a);
	}
}

static int	five1(t_ps_str *st)
{
	int fo;
	int ba;

	fo = findnum(st->a, 1, 1);
	ba = findnum(st->a, 1, 0);
	while (st->a->num != 1)
	{
		if (st->len == 5 && st->a->num == 2)
			push(&(st->b), &(st->a), 'b');
		if (fo > ba)
			rotate(&(st->a), 1, 'a');
		else
			rotate(&(st->a), 0, 'a');
		if (check_sort(st->a) == 0 && !st->b)
			return (1);
	}
	return (0);
}

static void	five2(t_ps_str *st)
{
	int fo;
	int ba;

	fo = findnum(st->a, 2, 1);
	ba = findnum(st->a, 2, 0);
	while ((st->a)->num != 2)
	{
		if (fo > ba)
			rotate(&(st->a), 1, 'a');
		else
			rotate(&(st->a), 0, 'a');
	}
	push(&(st->b), &(st->a), 'b');
}

void		five(t_ps_str *st)
{
	if (st->mix > 0)
	{
		if (five1(st))
			return ;
		push(&(st->b), &(st->a), 'b');
		if (st->len == 5 && st->b == st->b->next)
			five2(st);
		st->mix = check_sort(st->a);
		three(st);
		push(&(st->a), &(st->b), 'a');
		push(&(st->a), &(st->b), 'a');
		if (st->a->num > st->a->next->num)
			swap(&(st->a), &(st->a)->next, 'a');
	}
}

int			sorting(t_two **a, t_two **b, int step)
{
	int fo;
	int ba;
	int flag;

	flag = 0;
	fo = findnum(*b, step, 1);
	ba = findnum(*b, step, 0);
	while ((*b)->num != step)
	{
		if ((*b)->num == (step - 1))
		{
			push(a, b, 'a');
			flag = 1;
		}
		else
			rotate(b, (fo > ba), 'b');
	}
	push(a, b, 'a');
	if (flag == 1)
	{
		swap(a, &(*a)->next, 'a');
		step--;
	}
	step--;
	return (step);
}
