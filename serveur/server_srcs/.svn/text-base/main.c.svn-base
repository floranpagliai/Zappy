/*
** main.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:41:57 2013 laurent loukopoulos
** Last update Sun May 26 00:41:58 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"

int		main(int ac, char **av)
{
  t_server	server;

  if (ac == 2)
    {
      ++av;
      init_server(&server, *av);
      server_loop(&server);
      destroy_server(&server);
    }
  else
    printf("Usage: %s port\n", *av);
  return (0);
}
