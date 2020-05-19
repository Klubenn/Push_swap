/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:06:32 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/06 11:06:34 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int			check_sorting(t_ps_str *st)
{
	t_two *tmp;

	tmp = st->a;
	if (st->b != NULL)
	{
		clean_struct(st, 0);
		return (-1);
	}
	else if (st->a)
	{
		st->a = st->a->next;
		while (st->a != tmp)
		{
			if (st->a->num < st->a->prev->num)
			{
				clean_struct(st, 0);
				return (-1);
			}
			st->a = st->a->next;
		}
	}
	return (clean_struct(st, 0));
}

static int	read_instruct2(char *line)
{
	int i;

	i = 0;
	while ((read(0, line, 1)))
	{
		if (*line == '\n')
		{
			*line = '\0';
			return (1);
		}
		if (i >= 3)
			return (-1);
		i++;
		line++;
	}
	if (i != 0)
	{
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}

int			read_instruct1(t_ps_str *st, t_two *tmp)
{
	int		stat;
	char	line[5];

	st->a->next = tmp->next;
	tmp->next->prev = st->a;
	free(tmp);
	st->a = st->a->next;
	while (1)
	{
		if (st->max < 61 && st->visual)
			animation(st);
		ft_bzero(line, 5);
		stat = read_instruct2(line);
		if (stat == -1)
			return (clean_struct(st, 1));
		if (stat == 0)
			break ;
		if ((processing(line, &(st->a), &(st->b)) == -5))
			return (clean_struct(st, 1));
	}
	return (check_sorting(st));
}
