##
## Makefile for zappy in /home/loukop_l//zappy-2016-paglia_f
## 
## Made by laurent loukopoulos
## Login   <loukop_l@epitech.net>
## 
## Started on  Wed Jul  3 00:02:46 2013 laurent loukopoulos
## Last update Wed Jul 10 17:42:33 2013 laurent loukopoulos
##

SERVER		= zappy_serveur
CLIENT		= zappy_client
GRAPH		= zappy_graph

DIR_SERVER	= ./
DIR_CLIENT	= ./
DIR_COMMON	= ./
DIR_GUI		= gui/

INCLUDE_CLIENT	= -I./$(DIR_CLIENT)/client/include
INCLUDE_SERVER	= -I./$(DIR_SERVER)/server/include

SERVER_SRCS	= $(DIR_SERVER)server/main.c			\
		  $(DIR_SERVER)server/destroy_server.c		\
		  $(DIR_SERVER)server/do_client.c		\
		  $(DIR_SERVER)server/do_server.c		\
		  $(DIR_SERVER)server/init_server.c		\
		  $(DIR_SERVER)server/my_relay.c		\
		  $(DIR_SERVER)server/server_loop.c		\
		  $(DIR_SERVER)server/my_write.c		\
		  $(DIR_SERVER)server/my_game.c			\
		  $(DIR_SERVER)server/my_enroll.c		\
		  $(DIR_SERVER)server/my_checks_param.c		\
		  $(DIR_SERVER)server/my_checks_game.c		\
		  $(DIR_SERVER)server/my_check_names.c		\
		  $(DIR_SERVER)server/my_clock.c		\
		  $(DIR_SERVER)server/my_create_perso.c		\
		  $(DIR_SERVER)server/command.c			\
		  $(DIR_SERVER)server/get_index.c		\
		  $(DIR_SERVER)server/final_str_2.c		\
		  $(DIR_SERVER)server/final_str.c		\
		  $(DIR_SERVER)server/pop_res_2.c		\
		  $(DIR_SERVER)server/pop_res.c			\
		  $(DIR_SERVER)server/send_tab_rfc.c

CC		= gcc -g
CPP		= g++

CLIENT_SRCS	= $(DIR_CLIENT)client/main.cpp			\
		  $(DIR_CLIENT)client/Network.cpp		\
		  $(DIR_CLIENT)client/xfunc.cpp

COMMON_SRCS	= $(DIR_COMMON)common/xfunc_file.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS	= $(CLIENT_SRCS:.cpp=.o)
COMMON_OBJS	= $(COMMON_SRCS:.c=.o)


CFLAGS		+= -W -Wall -I$(DIR_COMMON)common/ -I. $(INCLUDE_SERVER)
CPPFLAGS	+= -W -Wall -I. $(INCLUDE_CLIENT)

RM		= rm -f

all		: $(SERVER) $(CLIENT) $(GRAPH)

$(SERVER)	: $(SERVER_OBJS) $(COMMON_OBJS)
		$(CC) -o $(SERVER) $(CFLAGS) $(SERVER_OBJS) $(COMMON_OBJS)
		@echo "ok server"

$(CLIENT)	: $(CLIENT_OBJS)
		$(CPP) -o $(CLIENT) $(CPPFLAGS) $(CLIENT_OBJS)
		@echo "ok client"

$(GRAPH)	:
		@(cd $(DIR_GUI) && $(MAKE))

clean		:
		$(RM) $(SERVER_OBJS)
		$(RM) $(COMMON_OBJS)
		$(RM) $(CLIENT_OBJS)
		@(cd $(DIR_GUI) && $(MAKE) $@)

fclean		: clean
		$(RM) $(SERVER)
		$(RM) $(CLIENT)
		@(cd $(DIR_GUI) && $(MAKE) $@)

re		: fclean all