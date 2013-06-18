NAME	=	zappy

DIR	=	src/

SRC	=	$(DIR)main.cpp\
		$(DIR)MyGame.cpp\
		$(DIR)Camera.cpp\
		$(DIR)Map.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

INCLUDES=	-I./include -I./lib/include

LDFLAGS	=	-L./lib -Wl,--rpath=./lib -lgdl_gl -lGL -lGLU

CFLAGS	=	-Wall -Werror

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		make clean

all:		$(NAME)

clean:
		rm -rf *.o
		rm -rf *~
		rm -rf *#

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@