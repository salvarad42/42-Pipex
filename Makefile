
NAME = pipex

SRC = ft_split_args.c ft_check_errors.c pipex.c

OBJS = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

LIBFT.A = ./libft/libft.a

RM = rm -rf

CC = gcc

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT.A}
		@${CC} ${CFLAGS} ${OBJS} ${LIBFT.A} -o ${NAME}

${LIBFT.A}:
		@${MAKE} -C ${LIBFT}

clean:
		@${MAKE} -C ${LIBFT} fclean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
