NAME		=	hello.so

SRC			=	hello.cpp				\

OBJS		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -g3 -std=c++17 -c -fpic

all:
	c++ $(CXXFLAGS) $(SRC)
	c++ -shared -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# .PHONY:		clean fclean re all
