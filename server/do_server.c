/*
** do_server.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:02:13 2013 laurent loukopoulos
** Last update Wed Jul  3 00:42:14 2013 laurent loukopoulos
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		"my_irc.h"
#include		"server_loop.h"
#include		"struct.h"
#include		"error.h"
#include		"my_game.h"

t_client*		new_client(int fd, t_server * server)
{
  t_client		*new;

  if (!(new = malloc(sizeof(*new))))
    return (NULL);
  new->fd = fd;
  new->write_start = 0;
  new->write_end = 0;
  new->read_start = 0;
  new->read_end = sprintf(new->buf_read, "%d logged.\n", fd - 3);
  new->next = NULL;
  my_send_all(server->clients, new);
  write(fd, "BIENVENUE\n", strlen("BIENVENUE\n"));

  return (new);
}

void			do_server(t_server * server, t_game * game)
{
  int			fd;
  struct sockaddr_in	csin;
  socklen_t		csin_len;
  t_client		*c;

  csin_len = sizeof(csin);
  if ((fd = accept(server->fd_server,
		   (struct sockaddr*)&csin, &csin_len)) == -1)
    error_and_destroy(ERROR_ACCEPT, server);
  if (!(server->clients))
    {
      if (!(server->clients = new_client(fd, server)))
	error_close_and_destoy(ERROR_MALLOC, server, fd);
    }
  else
    {
      c = server->clients;
      while (c->next)
	c = c->next;
      if (!(c->next = new_client(fd, server)))
	error_close_and_destoy(ERROR_MALLOC, server, fd);
    }
  printf("[ZAPPY] New client #%d from %s:%d\n", fd - 3,
	 inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
  my_clock(game);
}
