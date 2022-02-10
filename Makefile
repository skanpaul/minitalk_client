NAME	= client

CC		= gcc
CFLAG	= -Wall -Wextra -Werro
RM		= rm -f

SRC		= client.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $? -o $(NAME)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

run:
	./$(NAME)