NAME = parsing
CXX = cc
CXXFLAGS = #-Wall -Wextra -Werror #-fsanitize=address

CFILES = cub_parsing.c ft_strcmp.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c element_management.c file_management.c


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