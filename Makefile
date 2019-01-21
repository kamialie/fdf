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

EXE = fdf

LIB = libfdf.a

MLX = minilibx_macos/libmlx.a

SRC = main.c ft_file_to_list.c ft_image_man.c ft_draw_map.c ft_draw_line.c ft_rotation.c ft_deal_key.c ft_free_list.c ft_gradient.c ft_rotation_key.c ft_error.c ft_get_limit.c ft_spectrum_key.c

OBJ = $(SRC:.c=.o) 

LIB_SRC = $(addprefix libft/, $(shell ls libft | grep .c))

LIB_OBJ = $(LIB_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(EXE)

$(EXE): $(OBJ) $(LIB) $(MLX)
	gcc $(FLAGS) -o $(EXE) $(OBJ) $(LIB) -L minilibx_macos -l mlx -framework OpenGL -framework Appkit

.c.o:
	gcc $(FLAGS) -Ilibft -o $@ -c $<

$(LIB): $(LIB_OBJ)
	@ar rc $(LIB) $(LIB_OBJ)
	@ranlib $(LIB)

$(MLX):
	cd minilibx_macos && make

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(LIB_OBJ)

fclean: clean
	/bin/rm -f $(EXE)
	/bin/rm -f $(LIB)
	cd minilibx_macos && make clean

re: fclean all

.PHONY: all clean fclean re
