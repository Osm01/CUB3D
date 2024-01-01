NAME = raycasting

CXX = cc
CXXFLAGS = -fsanitize=address #-Wall -Wextra -Werror -fsanitize=address
COMPI =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC_RAYCASTING = raycasting.c
SRC_PARSING = ../parsing/cub_parsing.c ../parsing/ft_strcmp.c ../parsing/get_next_line/get_next_line.c \
              	../parsing/get_next_line/get_next_line_utils.c ../parsing/struct_element_operation.c  \
              	../parsing/file_management.c ../parsing/set_struct_elements.c ../parsing/check_elements.c ../parsing/map_manager.c \
              	../parsing/check_map.c ../parsing/check_map_addictional.c ../parsing/set_garbage_struct.c

all : $(NAME)

$(NAME) : $(SRC_RAYCASTING) LIBFT
	$(CXX) $(CXXFLAGS) $(SRC_RAYCASTING) $(SRC_PARSING) ../parsing/libft/libft.a $(COMPI) -o $(NAME)

LIBFT :
	make -C ../parsing/libft/

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all

.PHONY : all clean fclean re