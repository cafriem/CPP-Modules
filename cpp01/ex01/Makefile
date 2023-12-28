NAME = Zombie

CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = main.cpp zombieHorde.cpp Zombie.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re