# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 13:58:43 by gtristan          #+#    #+#              #
#    Updated: 2020/05/19 17:02:02 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CHECK = checker

LIBFT_DIR = ./libft/
LIBFT = lft
PRINTF_DIR = ./ft_printf/
PRINTF = lftprintf

INCL_DIR = ./includes/
INCL_H = ps_processing.h ps_shared.h push_swap.h ps_checker.h
INCL = $(addprefix $(INCL_DIR),$(INCL_H))

SRC_DIR = src/
SRC_PS_C = push_swap.c ps_01.c ps_02.c ps_03.c
SRC_CHECK_C = ps_animation.c ps_checker_01.c ps_checker_02.c ps_checker_03.c
SRC_SHARED_C = ps_shared_01.c ps_shared_02.c ps_shared_03.c ps_shared_04.c
SRC_PS = $(addprefix $(SRC_DIR),$(SRC_PS_C))
SRC_CHECK = $(addprefix $(SRC_DIR),$(SRC_CHECK_C))
SRC_SHARED = $(addprefix $(SRC_DIR),$(SRC_SHARED_C))

all: $(LIBFT_DIR)$(LIBFT) $(PRINTF_DIR)$(PRINTF) $(NAME_PS) $(NAME_CHECK)

$(LIBFT_DIR)$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME_PS): $(SRC_PS) $(SRC_SHARED) $(INCL)
	gcc $(SRC_PS) $(SRC_SHARED) -I$(INCL_DIR) -L$(LIBFT_DIR) -$(LIBFT) -L$(PRINTF_DIR) -$(PRINTF) -o $(NAME_PS)

$(NAME_CHECK): $(SRC_CHECK) $(SRC_SHARED) $(INCL)
	gcc $(SRC_CHECK) $(SRC_SHARED) -I$(INCL_DIR) -L$(LIBFT_DIR) -$(LIBFT) -L$(PRINTF_DIR) -$(PRINTF) -o $(NAME_CHECK)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME_PS)
	rm -f $(NAME_CHECK)

re: fclean all

.PHONY: all clean flcean re
