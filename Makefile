NAME		= minishell

SRCS		= src/main.c src/utils.c src/ft_strtrim_spaces_quotes.c src/ft_free.c \
				src/ft_print.c src/builtins.c src/ft_env_initial.c src/ft_env_builtins.c \
				src/ft_env_substitute.c src/ft_env_utils.c src/pipex/commands_bonus.c \
				src/pipex/commands_helper_bonus.c src/pipex/exec_bonus.c \
				src/pipex/main_bonus.c src/pipex/parser_bonus.c	src/pipex/path_bonus.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

INCLUDES	= -L libft -l ft -L ~/.brew/opt/readline/lib

INCLUDE		= -I libft -I ~/.brew/opt/readline/include

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

all:	${NAME}

%.o: %.c
ifeq ($(shell uname), Linux)
	${CC} ${CFLAGS} -o $@ -c $< -I libft
else
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDE}
endif

${NAME}: ${OBJS}
ifeq ($(shell uname), Linux)
	${CC} ${OBJS} -L libft -l ft -lreadline -o ${NAME} -g
else
	${CC} ${OBJS} ${LIBS} -lreadline -o ${NAME} -g ${INCLUDES}
endif

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re
