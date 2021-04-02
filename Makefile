NAME		=	a.out

LIBS		=	-ldl

CXXFLAGS	=	-Wall -Wextra -g3 -std=c++17

SRC			=	src/main.cpp			\
				src/core/core.cpp		\
				src/perso/perso.cpp		\
				src/map/map.cpp			\

OBJS		=	$(SRC:.cpp=.o)

CC			= c++

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)

all: $(NAME)
	cd libGraph && make

clean:
	rm -rf $(OBJS)
	cd libGraph && make clean

fclean: clean
	rm -f $(NAME)
	cd libGraph && make fclean

re: fclean all

.PHONY:		clean fclean re all