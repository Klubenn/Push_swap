/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:06 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:51:09 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_processing.h"

/*
** 1 - search forward, 0 - search reverse
*/

int		findnum(t_two *list, int num, int forward)
{
	int i;

	i = 0;
	while (list->num != num)
	{
		if (forward)
			list = list->next;
		else
			list = list->prev;
		i++;
	}
	return (i);
}

int		check_sort(t_two *list)
{
	t_two	*tmp;
	int		mix;

	mix = 0;
	if (list)
	{
		tmp = list;
		list = list->next;
		while (tmp != list)
		{
			if (list->num < list->prev->num)
				mix++;
			list = list->next;
		}
	}
	return (mix);
}

void	start_sort(t_ps_str *st, t_two *tmp)
{
	st->a->next = tmp->next;
	tmp->next->prev = st->a;
	free(tmp);
	st->a = st->a->next->next;
	tmp = st->a->prev;
	while (tmp != st->a)
	{
		if (st->a->num < st->a->prev->num)
			st->mix++;
		st->a = st->a->next;
	}
	st->mid = st->len / 2;
	st->max = st->len;
	if (st->mix && st->len <= 3)
		three(st);
	else if (st->mix && st->len <= 5)
		five(st);
	else if (st->mix && st->len <= 10)
		ten(st);
	else if (st->mix)
		big(st);
	clean_struct(st, 0);
}
