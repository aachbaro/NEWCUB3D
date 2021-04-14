NAME = cub3D
SRC = SRC/cub3d.c \
	  SRC/cub3d_utils.c \
	  SRC/cub3d_utils2.c \
	  SRC/PARCING/get_info.c \
	  SRC/PARCING/get_map.c \
	  SRC/PARCING/get_texture.c \
	  SRC/PARCING/get_texture2.c \
	  SRC/PARCING/parcing_utils.c \
	  SRC/PARCING/parcing_utils2.c \
	  SRC/PARCING/parcing_utils3.c \
	  SRC/RAYCASTING/window_utils.c \
	  SRC/RAYCASTING/window.c \
	  SRC/RAYCASTING/handle.c \
	  SRC/RAYCASTING/renders.c \
	  SRC/RAYCASTING/renders2.c \
	  SRC/RAYCASTING/renders3.c \
	  SRC/RAYCASTING/move.c \

#SAVE = save.bmp
LIBFT = -L./libft -lft
MLX = -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -rf
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
all: $(NAME)
clean:
	@${RM} ${OBJ}
fclean: clean
	@$(MAKE) fclean -C ./libft
	@${RM} ${SAVE}
	@${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
