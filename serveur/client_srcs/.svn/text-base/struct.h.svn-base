/*
** struct.h for zappy in /home/loukop_l//my_ircfinal/client_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:07:44 2013 laurent loukopoulos
** Last update Sun May 26 01:07:45 2013 laurent loukopoulos
*/

#ifndef		__STRUCT_H__
# define	__STRUCT_H__

# include	<sys/types.h>
# include	<sys/socket.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<netdb.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

# define		BUF_MAX	1024

typedef struct
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  int			cs;
  fd_set		fd_r;
  fd_set		fd_w;
  int			pos;
  char			buf[BUF_MAX];
  int			buf_ok;
}			t_client;

#endif
