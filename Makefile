NAME	=	philo
CC		=	gcc
FLAGS	=	-pthread -Wall -Wextra -Werror
RM		=	rm -f

INCLUDE		=	philo.h

SRC_FILES =	main.c \
			philo_utils.c \
			validate.c \
			init.c \
			time.c \
			dinner.c \
			dinner_utils.c \
			monitor.c \
			exit.c

SRC =	$(SRC_FILES)

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
