/*
** do_client.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:03:13 2013 laurent loukopoulos
** Last update Thu Jul 11 14:53:29 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"server_loop.h"
#include	"struct.h"
#include	"xfunc.h"
#include	"my_game.h"

t_client	*del_client(t_client *client, t_server * server, t_game *game)
{
  t_client	*c;

  (void)game;
  del_fd_graph(game, client->fd);
  printf("[ZAPPY] Client #%d disconnected.\n", client->fd - 3);
  if (client == server->clients)
    {
      server->clients = client->next;
      c = NULL;
    }
  else
    {
      c = server->clients;
      while (c->next != client)
	c = c->next;
      c->next = client->next;
    }
  xclose(client->fd);
  free(client);
  return (c);
}

t_client	*do_client_read(t_client *c, t_server *server, t_game *game)
{
  int		i;

  if (c->read_start < c->read_end)
    i = xread(c->fd, &(c->buf_read[c->write_start]),
	      c->read_end - c->read_start);
  else
    i = xread(c->fd, &(c->buf_read[c->read_start]),
	      BUF_MAX - c->read_start);
  if (i <= 0)
    return (del_client(c, server, game));
  else
    {
      if (c->read_start > c->read_end)
	i += xread(c->fd, c->buf_read,
		   c->read_end);
      c->read_end = (c->read_end + i) % BUF_MAX;
    }
  my_send_all(server->clients, c);
  my_game(c->buf_read, c->fd, game);
  return (c);
}

void		do_client_write(t_client *c)
{
  if (c->write_start < c->write_end)
    write(c->fd, &(c->buf_write[c->write_start]),
	  c->write_end - c->write_start);
  else
    {
      write(c->fd, &(c->buf_write[c->write_start]),
	    BUF_MAX - c->write_start);
      write(c->fd, c->buf_write,
	    c->write_end);
    }
  c->write_start = c->write_end;
}

void            do_client(t_server *server, t_game *game)
{
  t_client	*c;

  c = server->clients;
  while (c)
    {
      if (FD_ISSET(c->fd, &(server->fd_read)))
	c = do_client_read(c, server, game);
      if (c)
	c = c->next;
    }
}
