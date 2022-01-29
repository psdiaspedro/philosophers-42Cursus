NAME = philosophers
CC = gcc
FLAGS = -pthread -Wall -Wextra -Werror
RM = rm -f

SRC = main.c \
		dinner.c \
		init.c \
		philosophers_utils.c \
		time.c \
		validate.c \
		dinner_utils.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
