# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lde-la-h <lde-la-h@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 18:09:51 by lde-la-h      #+#    #+#                  #
#    Updated: 2021/11/12 16:30:03 by lde-la-h      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# //= Variables =// #

NAME = fdf
CFLAGS= -Wextra -Werror -Wall
GREEN = \x1b[32m
RESET = \033[0m
RED   = \x1b[31m

# Library location, maybe can be made more efficient
FDF= ./
LIBMLX= include/libmlx
LIBFT= include/libft
MLX= include/mlx

# Define the header location
HEADERS = -I $(LIBFT) -I $(MLX) -I $(LIBMLX) -I $(FDF)

# //= Files =// #

SRCS	= src/main.c \
		src/ft_project.c \
		src/ft_draw.c \
		src/ft_parse_map2.c \
		src/ft_error.c \
		src/ft_move.c \
		src/ft_height.c \
		src/ft_rotate.c \
		src/ft_zoom.c \

OBJS	= ${SRCS:.c=.o}

# //= Rules =// #

## //= Compile =// #
all: mlx libft libmlx $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) -O3

$(NAME): $(OBJS)
	@echo "$(RED)Compiling...$(GREEN)"
	$(CC) $(OBJS) $(HEADERS) $(LIBFT)/libft.a $(MLX)/libmlx.dylib $(LIBMLX)/libmlx.a -o $(NAME)
	@echo "$(RED)Done!$(RESET)"

#-g -fsanitize=address
## //= Commands =// #

# Compile mlx, if necessary...
mlx:
	@echo "$(RED)Checking mlx...$(GREEN)"
	@$(MAKE) -C $(MLX) && test -e libmlx.dylib || ln -sf $(MLX)/libmlx.dylib libmlx.dylib | echo "$(RED)Creaing symlink...$(RESET)"

# Compile libft, if necessary...
libft:
	@echo "$(RED)Checking libft...$(GREEN)"
	@$(MAKE) -C $(LIBFT)

# Compile libft, if necessary...
libmlx:
	@echo "$(RED)Checking libmlx...$(GREEN)"
	@$(MAKE) -C $(LIBMLX)

# Clean
clean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(MLX) clean

# Full clean
fclean: clean
	@echo "$(RED)Checking libmlx...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean
	@rm -f libmlx.dylib

# Re-compile
re:	fclean all

## //= Misc =// #

# Phonies as not to confuse make, these are actual commands, not files.
.PHONY: all, clean, fclean, re, mlx, libft