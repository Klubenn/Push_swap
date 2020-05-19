/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_shared.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:52:24 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/10 17:09:50 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SHARED_H
# define PS_SHARED_H

# include "../ft_printf/includes/header_pf.h"
# include "../libft/libft.h"

typedef struct	s_ps_str
{
	t_two		*a;
	t_two		*b;
	t_two		*anim_a;
	t_two		*anim_b;
	int			len;
	int			mid;
	int			max;
	int			mix;
	int			steps;
	int			visual;
}				t_ps_str;

t_ps_str		*new_struc_ps(void);
int				separation_ps(char *str, t_two **a);
int				clean_lists_err(t_ps_str *struc, int err);
int				check_dupl(t_two *a);
int				atoi_ps(char *str, int *num);
void			rotate(t_two **list, int reverse, char c);
void			ro_rotate(t_two **a, t_two **b, int reverse);
void			push(t_two **to, t_two **from, char letter);
void			push1(t_two **to, t_two **from, char letter);
void			swap(t_two **list1, t_two **list2, char letter);
void			make_array(t_two *a, int len);
int				clean_struct(t_ps_str *st, int err);

#endif
