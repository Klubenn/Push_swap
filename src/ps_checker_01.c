/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:06:13 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/06 11:06:16 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static int	check_flags(char *str)
{
	if (str[0] == '-' && str[1] == 'v' && str[2] == '\0')
		return (1);
	return (0);
}

static int	read_string_checker(int ac, char **av)
{
	t_ps_str	*st;
	t_two		*tmp;
	int			i;
	int			count;

	st = new_struc_ps();
	st->a = ft_new_two(0, NULL, NULL);
	tmp = st->a;
	i = 0;
	if ((i += check_flags(av[1])))
		st->visual = 1;
	while (++i <= ac)
	{
		if (!*av[i])
			continue ;
		if ((count = separation_ps(av[i], &(st->a))) == -5)
			return (clean_lists_err(st, 1));
		st->len += count;
	}
	if ((check_dupl(st->a) == -5))
		return (clean_lists_err(st, 1));
	if (st->a == tmp)
		return (clean_lists_err(st, 0));
	make_array(tmp->next, st->len);
	return (read_instruct1(st, tmp));
}

int			main(int ac, char **av)
{
	int a;

	if (ac > 1)
	{
		a = read_string_checker(ac - 1, av);
		if (a == 1)
			ft_putstr("OK\n");
		else if (a == -1)
			ft_putstr("KO\n");
		else if (a == 0)
			return (0);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
