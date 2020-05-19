/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_shared_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:52:12 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:52:14 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

void	swap(t_two **list1, t_two **list2, char letter)
{
	int i;

	if (list1 && list2 && list1 != list2)
	{
		i = (*list1)->num;
		(*list1)->num = (*list2)->num;
		(*list2)->num = i;
	}
	if (letter == 'a')
		ft_printf("sa\n");
	else if (letter == 'b')
		ft_printf("sb\n");
}

void	push1(t_two **to, t_two **from, char letter)
{
	t_two *tmp1;
	t_two *tmp2;

	tmp1 = *from;
	if (*from == (*from)->next)
		*from = NULL;
	else
	{
		*from = (*from)->next;
		(*from)->prev = (*from)->prev->prev;
		(*from)->prev->next = *from;
	}
	tmp2 = (*to)->prev;
	*to = tmp1;
	(*to)->prev = tmp2;
	(*to)->next = tmp2->next;
	tmp2->next = *to;
	(*to)->next->prev = *to;
	if (letter)
		ft_printf("p%c\n", letter);
}

void	push(t_two **to, t_two **from, char letter)
{
	if (!*to && *from)
	{
		*to = *from;
		if (*from == (*from)->next)
			*from = NULL;
		else
		{
			*from = (*from)->next;
			(*from)->prev = (*from)->prev->prev;
			(*from)->prev->next = *from;
		}
		(*to)->next = *to;
		(*to)->prev = *to;
		if (letter)
			ft_printf("p%c\n", letter);
	}
	else if (*to && *from)
		push1(to, from, letter);
}

void	ro_rotate(t_two **a, t_two **b, int reverse)
{
	if (*a && reverse == 0)
		*a = (*a)->next;
	if (*b && reverse == 0)
		*b = (*b)->next;
	if (*a && reverse == 1)
		*a = (*a)->prev;
	if (*b && reverse == 1)
		*b = (*b)->prev;
	if (reverse == 0)
		ft_printf("rr\n");
	else
		ft_printf("rrr\n");
}

void	rotate(t_two **list, int reverse, char c)
{
	if (*list && reverse == 0)
	{
		*list = (*list)->next;
		if (c)
			ft_printf("r%c\n", c);
	}
	if (*list && reverse == 1)
	{
		*list = (*list)->prev;
		if (c)
			ft_printf("rr%c\n", c);
	}
}
