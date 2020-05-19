/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_shared_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:51:57 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/05 14:52:06 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	wrong_sym(char c)
{
	if (c >= 58 || c <= 47)
	{
		if (c == ' ' || (c >= 9 && c <= 13) || c == 0)
			return (0);
		return (1);
	}
	return (0);
}

static int	atoi_ps1(char *str, int *sign, int *err)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
		(*err)++;
	}
	else if (str[i] == '+')
	{
		(*err)++;
		i++;
	}
	return (i);
}

int			atoi_ps(char *str, int *move)
{
	long long	res;
	int			sign;
	int			len;
	int			num;
	int			err;

	sign = 1;
	res = 0;
	len = 0;
	err = 0;
	*move = atoi_ps1(str, &sign, &err);
	while (str[*move] >= '0' && str[*move] <= '9' && len <= 10)
	{
		res = res * 10 + (str[*move] - '0');
		(*move)++;
		len++;
	}
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1)
		|| len > 10 || wrong_sym(str[*move]) || (len == 0 && err))
		*move = -5;
	else if (len == 0 && sign == 1)
		*move = 0;
	num = (int)res * sign;
	return (num);
}
