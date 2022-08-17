NAME		= minishell

SRCS		= src/main.c src/utils.c src/minilibft.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

INCLUDES	= -I includes

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDES}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${LIBS} ${INCLUDES} -lreadline -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re
