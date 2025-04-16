NAME    = cube
CC      = gcc
# CFLAGS  = -Wall -Wextra -Werror

MLXFLAGS		= -L$(MINILIBX_PATH) -lmlx -lX11 -lXext -lm
MINILIBX_PATH	= ./minilibx-linux
LIBFTDIR = ./libft
LIBFT_A = $(LIBFTDIR)/libft.a

# CFLAGS  = -Wall -Wextra -Werror

SRCDIR  = ./src
GNLDIR  = ./gnl
OBJDIR  = ./obj

SRCS    = $(SRCDIR)/main.c \
          $(SRCDIR)/parsing.c \
          $(SRCDIR)/error.c \
          $(SRCDIR)/init.c \
          $(SRCDIR)/check_map.c \
          $(SRCDIR)/verify_map.c \
          $(SRCDIR)/textures.c \
          $(SRCDIR)/tools2.c \
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
		  $(SRCDIR)/utils_ray.c \
		  $(SRCDIR)/display_bis.c \
		  $(SRCDIR)/raycasting_bis.c \

OBJS    = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(MINILIBX_PATH)/libmlx.a $(LIBFT_A) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLXFLAGS) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFTDIR)

$(MINILIBX_PATH)/libmlx.a:
	@$(MAKE) -C $(MINILIBX_PATH)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MINILIBX_PATH) clean  # ✅ Nettoie aussi mlx

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(MAKE) -C $(MINILIBX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
