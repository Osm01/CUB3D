NAME = parsing
CXX = cc
CXXFLAGS = #-Wall -Wextra -Werror #-fsanitize=address

CFILES = cub_parsing.c ft_strcmp.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c struct_element_operation.c  \
		file_management.c set_struct_elements.c check_elements.c map_manager.c \
		check_map.c check_map_addictional.c

all : $(NAME)

$(NAME) : $(CFILES) LIBFT
	$(CXX) $(CXXFLAGS) $(CFILES) ./libft/libft.a  -o $(NAME)

LIBFT :
	make -C libft/


clean :
	rm -rf $(NAME) ; make clean -C ./libft/

fclean :
	rm -rf $(NAME) ; make fclean -C ./libft/

re : fclean all

.PHONY : all clean fclean re