NAME_GUI=	zappy_gui

DIR_GUI	=	gui/

SRC_GUI	=	$(DIR_GUI)src/main.cpp\
		$(DIR_GUI)src/MyGame.cpp\
		$(DIR_GUI)src/Camera.cpp\
		$(DIR_GUI)src/Ground.cpp\
		$(DIR_GUI)src/IRessourceManager.cpp\
		$(DIR_GUI)src/Trantorien.cpp

OBJ_GUI	=	$(SRC_GUI:.cpp=.o)

CC	=	g++

INCLUDES_GUI=	-I./$(DIR_GUI)include -I./$(DIR_GUI)lib/include

LDFLAGS_GUI=	-L./$(DIR_GUI)lib -Wl,--rpath=./$(DIR_GUI)lib -lgdl_gl -lGL -lGLU

CFLAGS	=	-Wall -Werror

$(NAME_GUI):	$(OBJ_GUI)
		$(CC) -o $(NAME_GUI) $(OBJ_GUI) $(LDFLAGS_GUI)
		make clean

all:		$(NAME_GUI)

clean:
		rm -R -f $(DIR_GUI)*.o
		rm -R -f *~
		rm -R -f *#

fclean:		clean
		rm -rf $(NAME_GUI)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDES_GUI) -c $< -o $@