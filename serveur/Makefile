##
## Makefile for my_irc in /home/pojer_s/Documents/SystemUnix/my_irc
## 
## Made by steven pojer
## Login   <pojer_s@epitech.net>
## 
## Started on  Sun Apr 24 22:48:44 2011 steven pojer
## Last update Wed Jun 19 18:02:26 2013 laurent loukopoulos
##

SERVER		= ./server_srcs/serveur
CLIENT		= ./client_srcs/client

SERVER_SRCS	= ./server_srcs/main.c			\
		  ./server_srcs/destroy_server.c	\
		  ./server_srcs/do_client.c		\
		  ./server_srcs/do_server.c		\
		  ./server_srcs/init_server.c		\
		  ./server_srcs/my_relay.c		\
		  ./server_srcs/server_loop.c		\
		  ./server_srcs/my_write.c		\
		  ./server_srcs/my_game.c

CLIENT_SRCS	= ./client_srcs/do_client.c	\
		  ./client_srcs/init.c		\
		  ./client_srcs/main.c

COMMON_SRCS	= ./common_srcs/xfunc_file.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
COMMON_OBJS	= $(COMMON_SRCS:.c=.o)

CC		= gcc
CFLAGS		+= -W -Wall -I./common_srcs/ -I. -I./server_srcs/ -I./client_srcs/
RM		= rm -f

all		: $(SERVER) $(CLIENT)

$(SERVER)	: $(SERVER_OBJS) $(COMMON_OBJS)
		$(CC) -o $@ $^

$(CLIENT)	: $(CLIENT_OBJS)
		$(CC) -o $@ $^

clean		:
		$(RM) $(SERVER_OBJS)
		$(RM) $(COMMON_OBJS)
		$(RM) $(CLIENT_OBJS)

fclean		: clean
		$(RM) $(SERVER)
		$(RM) $(CLIENT)

re		: fclean all
