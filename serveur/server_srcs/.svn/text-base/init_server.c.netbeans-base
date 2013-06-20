/*
** init_server.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:01:55 2013 laurent loukopoulos
** Last update Sun May 26 01:01:56 2013 laurent loukopoulos
*/

#include	<netdb.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/time.h>
#include	<sys/resource.h>
#include	<unistd.h>
#include	"struct.h"
#include	"my_irc.h"
#include	"error.h"

void			init_server(t_server * server, char const * s_port)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  struct rlimit		rlp;

  server->port = atoi(s_port);
  server->clients = NULL;
  if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
    error(ERROR_GETRLIMIT);
  server->open_max = rlp.rlim_cur - 1;
  if ((pe = getprotobyname("tcp")) == NULL)
    error(ERROR_GETPROTOBYNAME);
  if ((server->fd_server = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    error(ERROR_SOCKET);
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(server->port);
  if (bind(server->fd_server, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    error_and_close(ERROR_BIND, server->fd_server);
  if (listen(server->fd_server, NB_LISTEN) == -1)
    error_and_close(ERROR_LISTEN, server->fd_server);
}
