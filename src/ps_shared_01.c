/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_shared_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:49 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:51:51 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

t_ps_str	*new_struc_ps(void)
{
	t_ps_str	*list;

	list = (t_ps_str *)malloc(sizeof(t_ps_str));
	if (!list)
		return (NULL);
	list->a = NULL;
	list->b = NULL;
	list->anim_a = NULL;
	list->anim_b = NULL;
	list->mid = 0;
	list->max = 0;
	list->mix = 0;
	list->len = 0;
	list->steps = 0;
	list->visual = 0;
	return (list);
}

int			clean_struct(t_ps_str *st, int err)
{
	t_two *tmp;

	if (st->a)
		st->a->prev->next = NULL;
	while (st->a)
	{
		tmp = st->a;
		st->a = st->a->next;
		free(tmp);
	}
	if (st->b)
		st->b->prev->next = NULL;
	while (st->b)
	{
		tmp = st->b;
		st->b = st->b->next;
		free(tmp);
	}
	free(st);
	if (err)
		return (-5);
	return (1);
}

int			check_dupl(t_two *a)
{
	t_two *tmp;

	while (a->prev)
	{
		tmp = a->prev;
		while (tmp->prev)
		{
			if (tmp->num == a->num)
				return (-5);
			tmp = tmp->prev;
		}
		a = a->prev;
	}
	return (0);
}

int			clean_lists_err(t_ps_str *struc, int err)
{
	t_two *tmp;

	while (struc->a)
	{
		tmp = struc->a->prev;
		free(struc->a);
		struc->a = tmp;
	}
	free(struc);
	if (err)
		return (-5);
	return (0);
}

int			separation_ps(char *str, t_two **a)
{
	int move;
	int num;
	int len;

	move = 0;
	len = 0;
	while (*str)
	{
		num = atoi_ps(str, &move);
		if (move == -5)
			return (-5);
		if (!move)
			break ;
		(*a)->next = ft_new_two(num, *a, NULL);
		str += move;
		*a = (*a)->next;
		len++;
	}
	return (len);
}
