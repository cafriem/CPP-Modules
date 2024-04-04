NAME = base

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp Start.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re