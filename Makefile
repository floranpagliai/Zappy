NAME_SERVER =	zappy_server

NAME_CLIENT =	zappy_client

NAME_GUI    =	zappy_gui

DIR_SERVER  =	serveur/

DIR_CLIENT  =	client/

DIR_GUI	    =	gui/

SRC_SERVER  =	$(DIR_CLIENT)src/main.c\
		$(DIR_CLIENT)src/destroy_server.c\
		$(DIR_CLIENT)src/do_client.c\
		$(DIR_CLIENT)src/do_server.c\
		$(DIR_CLIENT)src/init_server.c\
		$(DIR_CLIENT)src/my_relay.c\
		$(DIR_CLIENT)src/server_loop.c\
		$(DIR_CLIENT)src/my_write.c\
		$(DIR_CLIENT)src/my_game.c

SRC_CLIENT  =	$(DIR_CLIENT)src/main.c\

SRC_GUI	    =	$(DIR_GUI)src/main.cpp\
		$(DIR_GUI)src/MyGame.cpp\
		$(DIR_GUI)src/Network.cpp\
		$(DIR_GUI)src/Map.cpp\
		$(DIR_GUI)src/Camera.cpp\
		$(DIR_GUI)src/MapElement.cpp\
		$(DIR_GUI)src/IRessourceManager.cpp\
		$(DIR_GUI)src/Player.cpp\
		$(DIR_GUI)src/Parseur.cpp

OBJ_CLIENT  =	$(SRC_SERVER:.c=.o)

OBJ_CLIENT  =	$(SRC_CLIENT:.c=.o)

OBJ_GUI	    =	$(SRC_GUI:.cpp=.o)

CC	    =	g++

INCLUDE_CLIENT= -I./$(DIR_CLIENT)include

INCLUDE_GUI=	-I./$(DIR_GUI)include -I./$(DIR_GUI)lib/include

LDFLAGS_GUI =	-L./$(DIR_GUI)lib -Wl,--rpath=./$(DIR_GUI)lib -lgdl_gl -lGL -lGLU -lpthread

CFLAGS	    =	-Wall -Werror

$(NAME_GUI):	$(OBJ_GUI)
		$(CC) -o $(NAME_GUI) $(OBJ_GUI) $(LDFLAGS_GUI)
		make clean

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(INCLUDE_CLIENT) $(CFLAGS)
		make clean

all:		$(NAME_GUI)

clean:
		rm -f $(OBJ_GUI)
		rm -R -f *~
		rm -R -f *#

fclean:		clean
		rm -rf $(NAME_GUI)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDE_GUI) -c $< -o $@