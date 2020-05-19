/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:06:21 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/06 11:06:23 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static int	command1(char *line)
{
	if (*(line + 1) == 'a' && !*(line + 2))
		return (RA);
	else if (*(line + 1) == 'b' && !*(line + 2))
		return (RB);
	else if (*(line + 1) == 'r' && !*(line + 2))
		return (RR);
	else if (*(line + 1) == 'r' && *(line + 2) == 'a' && !*(line + 3))
		return (RRA);
	else if (*(line + 1) == 'r' && *(line + 2) == 'b' && !*(line + 3))
		return (RRB);
	else if (*(line + 1) == 'r' && *(line + 2) == 'r' && !*(line + 3))
		return (RRR);
	return (-1);
}

int			command(char *line)
{
	if (line == NULL)
		return (0);
	if (*line == 's')
	{
		if (*(line + 1) == 's' && !*(line + 2))
			return (SS);
		else if (*(line + 1) == 'a' && !*(line + 2))
			return (SA);
		else if (*(line + 1) == 'b' && !*(line + 2))
			return (SB);
	}
	else if (*line == 'p')
	{
		if (*(line + 1) == 'a' && !*(line + 2))
			return (PA);
		else if (*(line + 1) == 'b' && !*(line + 2))
			return (PB);
	}
	else if (*line == 'r')
		return (command1(line));
	return (-1);
}

static void	processing1(int pr, t_two **lista, t_two **listb)
{
	if (pr == PA)
		push(lista, listb, 0);
	else if (pr == PB)
		push(listb, lista, 0);
	else if (pr == RA)
		rotate(lista, 0, 0);
	else if (pr == RB)
		rotate(listb, 0, 0);
	else if (pr == RR)
	{
		rotate(lista, 0, 0);
		rotate(listb, 0, 0);
	}
	else if (pr == RRA)
		rotate(lista, 1, 0);
	else if (pr == RRB)
		rotate(listb, 1, 0);
	else if (pr == RRR)
	{
		rotate(lista, 1, 0);
		rotate(listb, 1, 0);
	}
}

int			processing(char *line, t_two **lista, t_two **listb)
{
	int pr;

	pr = command(line);
	if (pr == -1)
		return (-5);
	if (pr == SA && *lista)
		swap(lista, &(*lista)->next, 0);
	else if (pr == SB && *listb)
		swap(listb, &(*listb)->next, 0);
	else if (pr == SS)
	{
		if (*lista)
			swap(lista, &(*lista)->next, 0);
		if (*listb)
			swap(listb, &(*listb)->next, 0);
	}
	else if (pr == PA || pr == PB || pr == RA || pr == RB || pr == RR
			|| pr == RRA || pr == RRB || pr == RRR)
		processing1(pr, lista, listb);
	return (1);
}
