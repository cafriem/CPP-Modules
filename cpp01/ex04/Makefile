NAME = sed

CXX = c++

CXXFLAGS = main.cpp

SRCS = main.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re