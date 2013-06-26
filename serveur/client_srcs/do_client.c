/*
** do_client.c for zappy in /home/loukop_l//my_ircfinal/client_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:09:30 2013 laurent loukopoulos
** Last update Tue Jun 18 11:50:52 2013 laurent loukopoulos
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"do_client.h"
#include	"error.h"

void		check_stdin(t_client *client)
{
  int		i;

  if (FD_ISSET(0, &(client->fd_r)))
    {
      i = read(0, &(client->buf[client->pos]),
	       BUF_MAX - 1 - client->pos);
      if (i > 0)
	{
	  client->pos += i;
	  client->buf[client->pos] = 0;
	  client->buf_ok = 1;
	}
    }
}

int		get_data(t_client *client)
{
  int		i;
  char		buf[512];

  i = read(client->s, buf, 512);
  if (i <= 0)
    {
      fprintf(stderr, "Connexion close.\n");
      return (-1);
    }
  write(1, buf, i);
  return (0);
}

int		check_socket(t_client *client)
{
  int		i;

  if (FD_ISSET(client->s, &(client->fd_r)))
    {
      if (FD_ISSET(0, &(client->fd_r)))
	{
	  i = read(0, &(client->buf[client->pos]),
		   BUF_MAX - 1 - client->pos);
	  client->pos += i;
	  client->buf[client->pos] = 0;
	}
      i = get_data(client);
      write(1, client->buf, client->pos);
      return (i);
    }
  if (FD_ISSET(client->s, &(client->fd_w)))
    {
      write(client->s, client->buf, client->pos);
      client->buf_ok = 0;
      client->pos = 0;
    }
  return (0);
}

void		do_client(t_client *client)
{
  int		ok;

  ok = 1;
  if ((client->cs = connect(client->s,
			    (struct sockaddr *)&(client->sin),
			    sizeof (struct sockaddr_in))) == -1)
    error(ERROR_CONNECT);
  while (ok != -1)
    {
      FD_ZERO(&(client->fd_r));
      FD_ZERO(&(client->fd_w));
      FD_SET(0, &(client->fd_r));
      FD_SET(client->s, &(client->fd_r));
      if (client->buf_ok)
	FD_SET(client->s, &(client->fd_w));
      if ((ok = select(client->s + 1, &(client->fd_r),
		       &(client->fd_w), NULL, NULL)) != -1)
	{
	  check_stdin(client);
	  ok = check_socket(client);
	}
    }
}
