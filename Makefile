NAME_CLIENT =	zappy_client

NAME_GUI    =	zappy_gui

DIR_CLIENT  =	client/

DIR_GUI	    =	gui/

SRC_CLIENT  =	$(DIR_CLIENT)src/main.c\

SRC_GUI	    =	$(DIR_GUI)src/main.cpp\
		$(DIR_GUI)src/MyGame.cpp\
		$(DIR_GUI)src/Camera.cpp\
		$(DIR_GUI)src/Ground.cpp\
		$(DIR_GUI)src/IRessourceManager.cpp\
		$(DIR_GUI)src/Trantorien.cpp

OBJ_CLIENT  =	$(SRC_CLIENT:.c=.o)

OBJ_GUI	    =	$(SRC_GUI:.cpp=.o)

CC	    =	g++

INCLUDE_CLIENT= -I./$(DIR_CLIENT)include

INCLUDE_GUI=	-I./$(DIR_GUI)include -I./$(DIR_GUI)lib/include

LDFLAGS_GUI =	-L./$(DIR_GUI)lib -Wl,--rpath=./$(DIR_GUI)lib -lgdl_gl -lGL -lGLU

CFLAGS	    =	-Wall -Werror

$(NAME_GUI):	$(OBJ_GUI)
		$(CC) -o $(NAME_GUI) $(OBJ_GUI) $(LDFLAGS_GUI)
		make clean

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(INCLUDE_CLIENT) $(CFLAGS)
		make clean

all:		$(NAME_GUI) $(NAME_CLIENT)

clean:
		rm -R -f *.o
		rm -R -f *~
		rm -R -f *#

fclean:		clean
		rm -rf $(NAME_GUI)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDE_GUI) -c $< -o $@