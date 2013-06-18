/*
** init.c for zappy in /home/loukop_l//my_ircfinal/client_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:09:06 2013 laurent loukopoulos
** Last update Sun May 26 01:09:07 2013 laurent loukopoulos
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<netdb.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<stdlib.h>
#include	"init.h"
#include	"struct.h"
#include	"error.h"

void		client_init(int port, char *ip, t_client *client)
{
  client->pe = getprotobyname("TCP");
  if ((client->s = socket(AF_INET, SOCK_STREAM, client->pe->p_proto)) == -1)
    error(ERROR_SOCKET);
  client->sin.sin_family = AF_INET;
  client->sin.sin_port = htons(port);
  if ((int)(client->sin.sin_addr.s_addr = inet_addr(ip)) == -1)
    error("error");
  client->pos = 0;
  client->buf_ok = 0;
}

void		client_close(t_client *client)
{
  close(client->s);
}
