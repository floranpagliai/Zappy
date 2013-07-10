/*
** server_loop.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:47:34 2013 laurent loukopoulos
** Last update Tue Jul  2 15:43:57 2013 laurent loukopoulos
*/

#include	<stdlib.h>
#include	"my_irc.h"
#include	"server_loop.h"
#include	"struct.h"
#include	"my_game.h"

# define	MAX(a, b)	((a) > (b) ? (a) : (b))

void		init_loop(t_server * server)
{
  t_client	*client_list;

  FD_ZERO(&(server->fd_read));
  FD_ZERO(&(server->fd_write));
  FD_SET(server->fd_server, &(server->fd_read));
  client_list = server->clients;
  server->fd_max = 3;
  while (client_list)
    {
      server->fd_max = MAX(server->fd_max, client_list->fd);
      FD_SET(client_list->fd, &(server->fd_read));
      if (client_list->write_start != client_list->write_end)
	FD_SET(client_list->fd, &(server->fd_write));
      client_list = client_list->next;
    }
}

void		server_loop(t_server * server, t_game *game)
{
  int		ok;

  ok = 0;
  while (ok != -1)
    {
      init_loop(server);
      if ((ok = select(server->fd_max + 1, &(server->fd_read),
		       &(server->fd_write), NULL, NULL)) != -1)
	{
	  if (FD_ISSET(server->fd_server, &(server->fd_read)))
	    do_server(server, game);
	  do_client(server, game);
	}
    }
}
