# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 20:14:34 by ngonzale          #+#    #+#              #
#    Updated: 2022/06/03 15:49:06 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES	=  ft_types ft_flags ft_flag_plus ft_flag_hash ft_flag_space ft_printf

SRCS	= $(addsuffix .c, $(FILES))

OBJS	= $(addsuffix .o, $(FILES))

CC		= gcc

INCLUDE	= -I ../..

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(NAME):		$(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
