NAME	=	zappy

DIR	=	client/src/

SRC	=	$(DIR)main.cpp\
		$(DIR)MyGame.cpp\
		$(DIR)Camera.cpp\
		$(DIR)Ground.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

INCLUDES=	-I./client/include -I./client/lib/include

LDFLAGS	=	-L./client/lib -Wl,--rpath=./client/lib -lgdl_gl -lGL -lGLU

CFLAGS	=	-Wall -Werror

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		make clean

all:		$(NAME)

clean:
		rm -R -f *.o
		rm -R -f *~
		rm -R -f *#

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@