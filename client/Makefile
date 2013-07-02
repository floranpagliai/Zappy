NAME_CLIENT =	zappy_client

DIR_CLIENT  =	./

SRC_CLIENT  =	$(DIR_CLIENT)src/main.cpp\
		$(DIR_CLIENT)src/Network.cpp

OBJ_CLIENT  =	$(SRC_CLIENT:.cpp=.o)


CC	    =	g++

INCLUDE_CLIENT= -I./$(DIR_CLIENT)include

CFLAGS	    =	-Wall -Werror

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT)
		make clean

all:		$(NAME_CLIENT)

clean:
		rm -f $(OBJ_CLIENT)
		rm -R -f *~
		rm -R -f *#

fclean:		clean
		rm -rf $(NAME_CLIENT)

re:		fclean all

.cpp.o	:
		$(CC) $(CFLAGS) $(INCLUDE_CLIENT) -c $< -o $@