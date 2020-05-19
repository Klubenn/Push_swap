/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:50:45 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:50:56 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

static int		shakesort2(int *arr, int i, int *rotate)
{
	int tmp;

	if (arr[i] < arr[i - 1])
	{
		tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		(*rotate)++;
	}
	return (i);
}

static int		shakesort1(int *arr, int i, int *rotate)
{
	int tmp;

	if (arr[i] > arr[i + 1])
	{
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
		(*rotate)++;
	}
	i++;
	return (i);
}

static void		shakesort(int *arr, int len)
{
	int start;
	int end;
	int i;
	int rotate;

	start = 0;
	end = len - 1;
	while (start != end)
	{
		rotate = 0;
		i = start;
		while (i < end)
			i = shakesort1(arr, i, &rotate);
		end--;
		while (--i > start)
			i = shakesort2(arr, i, &rotate);
		start++;
		if (rotate == 0)
			break ;
	}
}

static void		change_nums(int *arr, t_two *list)
{
	int i;

	while (list)
	{
		i = 0;
		while (arr[i] != list->num)
			i++;
		list->num = i + 1;
		list = list->next;
	}
}

void			make_array(t_two *a, int len)
{
	t_two	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = a;
	arr = (int *)malloc(sizeof(int) * len);
	while (i < len && a)
	{
		arr[i] = a->num;
		a = a->next;
		i++;
	}
	shakesort(arr, len);
	change_nums(arr, tmp);
	free(arr);
}
