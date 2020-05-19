/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:52:56 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:52:58 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_processing.h"
#include "ps_shared.h"

int		read_string(int ac, char **av)
{
	t_ps_str	*st;
	t_two		*tmp;
	int			i;
	int			count;

	st = new_struc_ps();
	st->a = ft_new_two(0, NULL, NULL);
	tmp = st->a;
	i = 0;
	while (++i <= ac)
	{
		if (!*av[i])
			continue ;
		else if ((count = separation_ps(av[i], &(st->a))) == -5)
			return (clean_lists_err(st, 1));
		st->len += count;
	}
	if ((check_dupl(st->a) == -5))
		return (clean_lists_err(st, 1));
	if (st->a == tmp)
		return (clean_lists_err(st, 0));
	make_array(tmp->next, st->len);
	start_sort(st, tmp);
	return (0);
}

int		main(int ac, char **av)
{
	int a;

	if (ac > 1)
	{
		a = read_string(ac - 1, av);
		if (a == -5)
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
