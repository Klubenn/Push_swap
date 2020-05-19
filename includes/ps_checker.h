/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:05:58 by gtristan          #+#    #+#             */
/*   Updated: 2020/02/10 17:34:11 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define CLEAN "\e[1;1H\e[2J"

# include "../libft/libft.h"
# include "../ft_printf/includes/header_pf.h"
# include "ps_processing.h"
# include "ps_shared.h"

void	animation(t_ps_str *st);
int		command(char *line);
int		processing(char *line, t_two **lista, t_two **listb);
int		read_instruct1(t_ps_str *st, t_two *tmp);
int		check_sorting(t_ps_str *st);

#endif
