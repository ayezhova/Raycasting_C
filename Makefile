NAME = cub3d
SRC = srcs
OBJ = $(addprefix $(SRC)/,main.o check_map.o check_map_valid.o check_inputs.o \
	put_image.o put_image_small.o tile_image.o make_trapezoid_img.o)
OBJ_INC = raycasting.h
LIBFT = libft/libft.a
LIBFT_INC = libft/libft.h
MLX = minilibx_macos/libmlx.a
MLX_INC = minilibx_macos/mlx.h
MLX_DIR = minilibx_macos/
GNL = GNL/get_next_line.o
GNL_INC = GNL/get_next_line.h

all: $(NAME)

$(OBJDIR)/%.o : $(OBJ_INC) $(MLX_INC) $(LIBFT_INC)

$(GNL): $(GNL_INC)

$(LIBFT):
	make -C libft/

$(MLX):
	make -C minilibx_macos/

$(NAME): $(LIBFT) $(MLX) $(OBJ) $(GNL)
	@echo "Making cub3d..."
	@gcc -g $(OBJ) -I $(MLX_DIR) $(GNL) $(GNL_INC) $(LIBFT) -L $(MLX_DIR) \
		-lmlx -framework OpenGL -framework AppKit
	@mv a.out $(NAME)

clean:
	/bin/rm -r $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean
