NAME    = cube
MLXFLAGS		=	-L. -lXext -L. -lX11
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

MINILIBX_PATH	=	./minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

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
          $(SRCDIR)/verify_map.c \
          $(SRCDIR)/textures.c \
          $(SRCDIR)/xpm.c \
          $(SRCDIR)/tools.c \
		  $(SRCDIR)/check_map_layout.c \
          $(SRCDIR)/floor_ceiling.c \
          $(SRCDIR)/check_newline.c \
		  $(GNLDIR)/get_next_line_utils.c \
		  $(GNLDIR)/get_next_line.c \
		  $(SRCDIR)/display.c \
		  $(SRCDIR)/raycasting.c \
		  $(SRCDIR)/move.c \
		  $(SRCDIR)/move_bis.c \
		  $(SRCDIR)/launch.c \
		  $(SRCDIR)/ft_xpm_to_img.c \
		  $(SRCDIR)/init_ray.c \


OBJS    = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MINILIBX) \
	$(MLXFLAGS) -o $(NAME)

$(MINILIBX):
	@$(MAKE) -C $(MLXDIR)

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
