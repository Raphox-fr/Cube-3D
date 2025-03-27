NAME			=	ex01

SRCS			=	main.c

OBJS			=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra

all			:	${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean			:
	rm -rf ${OBJS}

fclean			:	clean
	rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re

# -Wall -Werror -Wextra -g3
