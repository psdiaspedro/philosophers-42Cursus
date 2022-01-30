NAME	=	philosophers
CC		=	gcc
FLAGS	=	-pthread -Wall -Wextra -Werror
RM		=	rm -f

INCLUDE_DIR	=	include
INCLUDE		=	$(INCLUDE_DIR)/philosophers.h

SRC_FILES =	main.c \
			dinner.c \
			init.c \
			philosophers_utils.c \
			time.c \
			validate.c \
			dinner_utils.c \
			exit.c

SRC =	$(addprefix src/, $(SRC_FILES))

OBJECTS = $(SRC:.c=.o)

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
