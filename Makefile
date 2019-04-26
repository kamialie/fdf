# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgyles <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 14:41:20 by rgyles            #+#    #+#              #
#    Updated: 2019/01/20 21:18:59 by rgyles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

MLX = minilibx_macos/libmlx.a

MLX_DIR = minilibx_macos

SRC = main.c\
	ft_file_to_list.c\
	ft_image_man.c\
	ft_draw_map.c\
	ft_draw_line.c\
	ft_rotation.c\
	ft_deal_key.c\
	ft_free_list.c\
	ft_gradient.c\
	ft_rotation_key.c\
	ft_error.c\
	ft_get_limit.c\
	ft_spectrum_key.c

SRC_DIR = sources

OBJ_DIR = object

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(MLX)
	gcc $(FLAGS) -I includes -o $(NAME) $(OBJ) $(LIB) $(MLX) -framework OpenGL -framework Appkit

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -I includes -o $@ -c $<

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean

fclean: clean
	/bin/rm -f $(EXE)
	@make -C $(LIB_DIR) fclean
	@make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
