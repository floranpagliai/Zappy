NAME    =	../zappy_gui

SRC	=	src/main.cpp\
		src/MyGame.cpp\
		src/Network.cpp\
		src/Map.cpp\
		src/Camera.cpp\
		src/MapElement.cpp\
		src/IRessourceManager.cpp\
		src/Player.cpp\
		src/Egg.cpp\
		src/Ressources.cpp\
		src/Parseur.cpp

OBJ	    =	$(SRC:.cpp=.o)

CC	    =	g++

INCLUDE	    =	-I./include -I./lib/include

LDFLAGS	    =	-L./lib -Wl,--rpath=./lib -lgdl_gl -lGL -lGLU -lpthread

CFLAGS	    =	-Wall -Werror

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		make clean

all:		$(NAME)

clean:
		@rm -f $(OBJ)
		@rm -R -f *~
		@rm -R -f *#

fclean:		clean
		@rm -rf $(NAME)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
