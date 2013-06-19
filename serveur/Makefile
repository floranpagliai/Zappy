##
## Makefile for my_irc in /home/pojer_s/Documents/SystemUnix/my_irc
##
## Made by steven pojer
## Login   <pojer_s@epitech.net>
##
## Started on  Sun Apr 24 22:48:44 2011 steven pojer
## Last update Sun May 26 01:39:09 2013 laurent loukopoulos
##

SERVER		= serveur


SERVER_SRCS	= ./server_srcs/main.c			\
		  ./server_srcs/destroy_server.c	\
		  ./server_srcs/do_client.c		\
		  ./server_srcs/do_server.c		\
		  ./server_srcs/init_server.c		\
		  ./server_srcs/my_relay.c		\
		  ./server_srcs/server_loop.c		\
		  ./server_srcs/my_write.c

COMMON_SRCS	= ./common_srcs/xfunc_file.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
COMMON_OBJS	= $(COMMON_SRCS:.c=.o)

CC		= gcc
CFLAGS		+= -W -Wall -I./common_srcs/ -I. -I./server_srcs/
RM		= rm -f

all		: $(SERVER)

$(SERVER)	: $(SERVER_OBJS) $(COMMON_OBJS)
		$(CC) -o $@ $^


clean		:
		$(RM) $(SERVER_OBJS)
		$(RM) $(COMMON_OBJS)

fclean		: clean
		$(RM) $(SERVER)

re		: fclean all
