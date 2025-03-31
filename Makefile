NAME    = cube
# CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCDIR  = ./src
GNLDIR = ./gnl
LIBFTDIR = ./libft
OBJDIR  = ./obj
LIBFT_A = $(LIBFTDIR)/libft.a

SRCS    = $(SRCDIR)/main.c \
          $(SRCDIR)/parsing.c \
          $(SRCDIR)/error.c \
          $(SRCDIR)/init.c \
          $(SRCDIR)/check_map.c \
          $(SRCDIR)/flood_fill.c \
          $(SRCDIR)/textures.c \
          $(SRCDIR)/xpm.c \
          $(SRCDIR)/tools.c \
		  $(SRCDIR)/check_map_layout.c \
          $(SRCDIR)/floor_ceiling.c \
		  $(GNLDIR)/get_next_line_utils.c \
		  $(GNLDIR)/get_next_line.c \


OBJS    = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re



# -Wall -Werror -Wextra -g3
