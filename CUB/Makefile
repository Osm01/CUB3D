# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 18:27:39 by nbaghoug          #+#    #+#              #
#    Updated: 2024/01/19 11:16:59 by nbaghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAMEB = cub3D_bonus
FILE_C = ./mand/parsing/check_elements.c                 ./mand/parsing/floor_ciel_operation.c           ./mand/parsing/struct_element_operation.c       ./mand/rendering/mouse.c \
			./mand/parsing/check_map.c                      ./mand/parsing/ft_strcmp.c                      ./mand/rendering/DDA.c                          ./mand/rendering/movement.c \
		./mand/parsing/check_map_addictional.c          ./mand/parsing/leaks_manager.c                  ./mand/rendering/Direction.c                    ./mand/rendering/put_entity.c\
		./mand/parsing/check_valid_element_addic.c      ./mand/parsing/map_manager.c                    ./mand/rendering/debuging.c                     ./mand/rendering/texture.c\
		./mand/parsing/cub_parsing.c                    ./mand/parsing/set_garbage_struct.c             ./mand/rendering/draw.c                         ./mand/rendering/utils.c\
		./mand/parsing/cub_parsing_utils.c              ./mand/parsing/set_struct_elements.c            ./mand/rendering/ft_draw_shape.c                ./mand/rendering/utils1.c\
		./mand/parsing/file_management.c                ./mand/parsing/setup_valid_map.c                ./mand/rendering/initialize_texture.c  ./mand/cub3D.c  ./mand/parsing/get_next_line/get_next_line.c  ./mand/parsing/get_next_line/get_next_line_utils.c

FILE_B = ./bonus/parsing/check_elements.c                 ./bonus/parsing/floor_ciel_operation.c           ./bonus/parsing/struct_element_operation.c       ./bonus/rendering/mouse.c \
			./bonus/parsing/check_map.c                      ./bonus/parsing/ft_strcmp.c                      ./bonus/rendering/DDA.c                          ./bonus/rendering/movement.c \
		./bonus/parsing/check_map_addictional.c          ./bonus/parsing/leaks_manager.c                  ./bonus/rendering/Direction.c                    ./bonus/rendering/put_entity.c\
		./bonus/parsing/check_valid_element_addic.c      ./bonus/parsing/map_manager.c                    ./bonus/rendering/debuging.c                     ./bonus/rendering/texture.c\
		./bonus/parsing/cub_parsing.c                    ./bonus/parsing/set_garbage_struct.c             ./bonus/rendering/draw.c                         ./bonus/rendering/utils.c\
		./bonus/parsing/cub_parsing_utils.c              ./bonus/parsing/set_struct_elements.c            ./bonus/rendering/ft_draw_shape.c                \
		./bonus/parsing/file_management.c                ./bonus/parsing/setup_valid_map.c                ./bonus/rendering/initialize_texture.c  ./bonus/cub3D_bonus.c  ./bonus/parsing/get_next_line/get_next_line.c\
		./bonus/parsing/get_next_line/get_next_line_utils.c ./bonus/animation_bonus.c                 ./bonus/utils_bonus.c

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address
CC = cc
all : $(NAME)
$(NAME): $(FILE_C)
	make -C ./mand/parsing/libft;   $(CC) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit $(FILE_C) ./mand/parsing/libft/libft.a -o $(NAME)

fclean : clean
	rm -rf $(NAME); make fclean -C ./mand/parsing/libft; ./bonus/parsing/libft; rm -rf $(NAMEB)

clean:
	make clean -C ./mand/parsing/libft
	make clean -C ./bonus/parsing/libft

bonus : $(NAMEB)
$(NAMEB) :$(FILE_B)
	make -C ./bonus/parsing/libft ;   $(CC) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit $(FILE_B) ./bonus/parsing/libft/libft.a -o $(NAMEB)
re : fclean all
.PHONY : all fclean clean re