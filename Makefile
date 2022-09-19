NAME		= minishell

SRCS		= src/main.c src/utils.c src/ft_strtrim_spaces.c src/ft_free.c \
				src/ft_print.c src/ft_env.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

INCLUDES	= -L libft -l ft -L ~/.brew/opt/readline/lib

INCLUDE		= -I libft -I ~/.brew/opt/readline/include

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDE}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${LIBS} -lreadline -o ${NAME} -g ${INCLUDES}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re
