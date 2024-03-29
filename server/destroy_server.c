/*
** destroy_server.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:03:22 2013 laurent loukopoulos
** Last update Tue Jun 18 14:09:03 2013 laurent loukopoulos
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_irc.h"
#include	"struct.h"

void		free_clients(t_client * c)
{
  if (c)
    {
      if (c->next)
	free_clients(c->next);
      close(c->fd);
      free(c);
    }
}

void		destroy_server(t_server * server)
{
  free_clients(server->clients);
  close(server->fd_server);
}
