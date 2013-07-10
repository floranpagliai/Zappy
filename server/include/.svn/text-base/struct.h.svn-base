/*
** struct.h for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:43:21 2013 laurent loukopoulos
** Last update Mon Jul  1 21:51:54 2013 laurent loukopoulos
*/

#ifndef			__STRUCT_H__
# define		__STRUCT_H__

#include		<sys/select.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		"my_game.h"

void			my_game(char *, int, t_game*);
char			*my_str(char *);
int			my_count_last_str(char *);

# define		BUF_MAX		512

typedef struct		s_client
{
  int			fd;
  int			read_start;
  int			read_end;
  int			write_start;
  int			write_end;
  char			buf_read[BUF_MAX];
  char			buf_write[BUF_MAX];
  struct s_client	*next;
}			t_client;

typedef struct
{
  int			fd_server;
  t_client		*clients;
  int			port;
  int			open_max;
  int			fd_max;
  fd_set		fd_read;
  fd_set		fd_write;
}			t_server;

#endif
