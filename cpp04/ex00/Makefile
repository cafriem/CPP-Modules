# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:21:45 by mkhan             #+#    #+#              #
#    Updated: 2023/01/08 20:04:31 by mkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

RM = rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = main

%.o : %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@printf "\033c"

clean:
	@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re