NAME	=	cube


SRCDIR	=	src

SRCS	=	$(SRCDIR)/main.c \
			$(SRCDIR)/parsing.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

# CFLAGS	=	-Werror -Wall -Wextra

all		:	${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re


# -Wall -Werror -Wextra -g3
