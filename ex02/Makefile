NAME	= ex00

CC		= c++ -Wall -Werror -Wextra 

CFLAGS	= -Wall -Werror -Wextra 

SRC	= main.cpp Fixed.cpp  


all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)

clean:		
	rm -f $(OBJ)

run:		$(NAME)
			./$(NAME)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re