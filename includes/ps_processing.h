/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_processing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:52:41 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/10 17:09:37 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PROCESSING_H
# define PS_PROCESSING_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "ps_shared.h"

int				read_string(int ac, char **av);
int				findnum(t_two *list, int num, int forward);
int				check_sort(t_two *list);
void			start_sort(t_ps_str *st, t_two *tmp);
void			three(t_ps_str *st);
void			five(t_ps_str *st);
int				sorting(t_two **a, t_two **b, int step);
void			ret_big(t_ps_str *st);
int				rem_big(t_ps_str *st, int step);
void			big(t_ps_str *st);
void			ten(t_ps_str *st);

#endif
