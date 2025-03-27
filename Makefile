NAME    = cube

SRCDIR  = ./src
GNLDIR = ./gnl

OBJDIR  = ./obj

SRCS    = $(SRCDIR)/main.c \
          $(SRCDIR)/parsing.c \
		  $(GNLDIR)/get_next_line_utils.c \
		  $(GNLDIR)/get_next_line.c \



OBJS    = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


CC      = gcc

# CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# -Wall -Werror -Wextra -g3
