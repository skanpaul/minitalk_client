NAME	= client

CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f

LIBFTPATH = .
LIBFTNAME = ft

HD		= client.h
SRC		= client.c \
			init_data.c \
			stream_out_char.c \
			stream_out_int.c \
			stream_out_string.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HD)
	$(CC) $(CFLAG) -L$(LIBFTPATH) -l$(LIBFTNAME) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

run:
	./$(NAME)